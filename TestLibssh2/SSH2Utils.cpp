/*
 * SSH2Utils.cpp
 *
 *  Created on: 2011-2-25
 *      Author: Yewberry
 */

#include "SSH2Utils.h"

char* SSH2Utils::ERR_MSG[] = {
		"unused",
		"Libssh2 initialization failed",
		"Socket connect failed",
		"Session init failed",
		"Failure establishing SSH session",
		"Authentication by password failed",
		"Authentication by keyboard-interactive failed",
		"Authentication by public key failed",
		"No supported authentication methods found",
		"Open channel failed",
		"Exec command line Error"
};


SSH2Utils::~SSH2Utils(void) {
	libssh2_exit();
}

static const char *_password="password";

void SSH2Utils::kbd_callback(const char *name, int name_len,
                         const char *instruction, int instruction_len,
                         int num_prompts,
                         const LIBSSH2_USERAUTH_KBDINT_PROMPT *prompts,
                         LIBSSH2_USERAUTH_KBDINT_RESPONSE *responses,
                         void **abstract)
{
    (void)name;
    (void)name_len;
    (void)instruction;
    (void)instruction_len;
    if (num_prompts == 1) {
        responses[0].text = strdup(_password);
        responses[0].length = strlen(_password);
    }
    (void)prompts;
    (void)abstract;
} /* kbd_callback */

int SSH2Utils::init(void) {
	m_errCode = 0;
	m_sock = 0;
	m_session = 0;
	keyfile1="~/.ssh/id_rsa.pub";
	keyfile2="~/.ssh/id_rsa";

#ifdef WIN32
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 0), &wsadata);
#endif
	int rc = 0;
	rc = libssh2_init(0);
	if (rc != 0) {
		fprintf(stderr, "libssh2 initialization failed (%d)\n", rc);
		m_errCode = 1;
		return -1;
	}
	return 0;
}
int SSH2Utils::connect(const char *hostname, const char *username,
		const char *password) {
    unsigned long hostaddr;
    int rc, sock, auth_pw = 0;
    struct sockaddr_in sin;
    const char *fingerprint;
    char *userauthlist;
    LIBSSH2_SESSION *session;

    _password = password;
    hostaddr = inet_addr(hostname);

    /* Ultra basic "connect to port 22 on localhost".  Your code is
     * responsible for creating the socket establishing the connection
     */
    sock = socket(AF_INET, SOCK_STREAM, 0);

    sin.sin_family = AF_INET;
    sin.sin_port = htons(22);
    sin.sin_addr.s_addr = hostaddr;
    if (::connect(sock, (struct sockaddr*)(&sin),
                sizeof(struct sockaddr_in)) != 0) {
        fprintf(stderr, "failed to connect!\n");
        m_errCode = 2;
        return -1;
    }

	/* Create a session instance */
    session = libssh2_session_init();
	if (!session) {
		m_errCode = 3;
		return -1;
	}

	/* tell libssh2 we want it all done non-blocking */
	//libssh2_session_set_blocking(session, 0);
	/* ... start it up. This will trade welcome banners, exchange keys,
	 * and setup crypto, compression, and MAC layers
	 */
	while ((rc = libssh2_session_startup(session, sock))
			== LIBSSH2_ERROR_EAGAIN)
		;
	if (rc) {
		fprintf(stderr, "Failure establishing SSH session: %d\n", rc);
		m_errCode = 4;
		return -1;
	}

    /* At this point we havn't authenticated. The first thing to do is check
     * the hostkey's fingerprint against our known hosts Your app may have it
     * hard coded, may go to a file, may present it to the user, that's your
     * call
     */
    fingerprint = libssh2_hostkey_hash(session, LIBSSH2_HOSTKEY_HASH_SHA1);
    printf("Fingerprint: ");
    for(int i = 0; i < 20; i++) {
        printf("%02X ", (unsigned char)fingerprint[i]);
    }
    printf("\n");

    /* check what authentication methods are available */
    userauthlist = libssh2_userauth_list(session, username, strlen(username));
    printf("Authentication methods: %s\n", userauthlist);
    if (strstr(userauthlist, "password") != NULL) {
        auth_pw |= 1;
    }
    if (strstr(userauthlist, "keyboard-interactive") != NULL) {
        auth_pw |= 2;
    }
    if (strstr(userauthlist, "publickey") != NULL) {
        auth_pw |= 4;
    }

    if (auth_pw & 1) {
        /* We could authenticate via password */
        if (libssh2_userauth_password(session, username, password)) {
            printf("\tAuthentication by password failed!\n");
            m_errCode = 5;
            goto shutdown;
        } else {
            printf("\tAuthentication by password succeeded.\n");
        }
    } else if (auth_pw & 2) {
        /* Or via keyboard-interactive */
        if (libssh2_userauth_keyboard_interactive(session, username,
                                                  &SSH2Utils::kbd_callback) ) {
            printf("\tAuthentication by keyboard-interactive failed!\n");
            m_errCode = 6;
            goto shutdown;
        } else {
            printf("\tAuthentication by keyboard-interactive succeeded.\n");
        }
    } else if (auth_pw & 4) {
        /* Or by public key */
        if (libssh2_userauth_publickey_fromfile(session, username, keyfile1,
                                                keyfile2, password)) {
            printf("\tAuthentication by public key failed!\n");
            m_errCode = 7;
            goto shutdown;
        } else {
            printf("\tAuthentication by public key succeeded.\n");
        }
    } else {
        printf("No supported authentication methods found!\n");
        m_errCode = 8;
        goto shutdown;
    }

    m_sock = sock;
    m_session = session;

    return 0;

shutdown:
    deconnect();
}

void SSH2Utils::deconnect() {
	libssh2_session_disconnect(m_session,
			"Normal Shutdown, Thank you for playing");
	libssh2_session_free(m_session);
#ifdef WIN32
	closesocket(m_sock);
#else
	close(m_sock);
#endif

	m_session = 0;
	m_sock = 0;
}

int SSH2Utils::reconnect(char *hostname, char *username, char *password) {
	deconnect();
	return connect(hostname, username, password);
}

int SSH2Utils::exec(char *cmd) {
	m_execResultStr.clear();
	int rc;
	LIBSSH2_CHANNEL *channel;
	/* Exec non-blocking on the remove host */
	while ((channel = libssh2_channel_open_session(m_session)) == NULL
			&& libssh2_session_last_error(m_session, NULL, NULL, 0)
					== LIBSSH2_ERROR_EAGAIN) {
		waitsocket();
	}
	if (channel == NULL) {
		fprintf(stderr, "Channel Error\n");
		m_errCode = 9;
		return -1;
	}
	while ((rc = libssh2_channel_exec(channel, cmd)) == LIBSSH2_ERROR_EAGAIN) {
		waitsocket();
	}
	if (rc != 0) {
		fprintf(stderr, "Exec command line Error\n");
		m_errCode = 10;
		return -1;
	}
	for (;;) {
		/* loop until we block */
		int rc;
		do {
			char buffer[BUF_SIZE];
			memset(buffer, 0, BUF_SIZE);
			rc = libssh2_channel_read(channel, buffer, sizeof(buffer));
			if (rc > 0) {
				m_execResultStr.append(buffer);
			}
		} while (rc > 0);
		/* this is due to blocking that would occur otherwise so we loop on
		 this condition */
		if (rc == LIBSSH2_ERROR_EAGAIN) {
			waitsocket();
		} else
			break;
	}
	m_channelExitCode = 127;
	while ((rc = libssh2_channel_close(channel)) == LIBSSH2_ERROR_EAGAIN)
		waitsocket();
	if (rc == 0) {
		m_channelExitCode = libssh2_channel_get_exit_status(channel);
	}
	libssh2_channel_free(channel);
	channel = NULL;
	return 0;
}

int SSH2Utils::waitsocket(void) {
	struct timeval timeout;
	int rc;
	fd_set fd;
	fd_set *writefd = NULL;
	fd_set *readfd = NULL;
	int dir;
	timeout.tv_sec = 10;
	timeout.tv_usec = 0;
	FD_ZERO(&fd);
	FD_SET(m_sock, &fd);
	/* now make sure we wait in the correct direction */
	dir = libssh2_session_block_directions(m_session);
	if (dir & LIBSSH2_SESSION_BLOCK_INBOUND)
		readfd = &fd;
	if (dir & LIBSSH2_SESSION_BLOCK_OUTBOUND)
		writefd = &fd;
	rc = select(m_sock + 1, readfd, writefd, NULL, &timeout);
	return rc;
}
