/*
 * SSH2Utils.h
 *
 *  Created on: 2011-2-25
 *      Author: Yewberry
 */

#ifndef SSH2UTILS_H_
#define SSH2UTILS_H_

#include <libssh2_config.h>
#include <libssh2.h>
#include <libssh2_sftp.h>

#ifdef HAVE_WINSOCK2_H
# include <winsock2.h>
#endif
#ifdef HAVE_SYS_SOCKET_H
# include <sys/socket.h>
#endif
#ifdef HAVE_NETINET_IN_H
# include <netinet/in.h>
#endif
#ifdef HAVE_SYS_SELECT_H
# include <sys/select.h>
#endif
# ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_ARPA_INET_H
# include <arpa/inet.h>
#endif
//#include <sys/time.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <ctype.h>
#include <string>

class SSH2Utils {
public:
	SSH2Utils(void) :
		m_errCode(0) {
	}
	int init(void);
	int connect(const char *hostname, const char *username,
			const char *password);
	void deconnect(void);
	int reconnect(char *hostname, char *username, char *password);
	int exec(char *cmd);

public:
	~SSH2Utils(void);
	int errCode() {
		return m_errCode;
	}
	const char* errMsg() {
		return ERR_MSG[m_errCode];
	}
	std::string execResultStr() {
		return m_execResultStr;
	}
	int channelExitCode() {
		return m_channelExitCode;
	}

private:
	static void kbd_callback(const char *name, int name_len,
	                         const char *instruction, int instruction_len,
	                         int num_prompts,
	                         const LIBSSH2_USERAUTH_KBDINT_PROMPT *prompts,
	                         LIBSSH2_USERAUTH_KBDINT_RESPONSE *responses,
	                         void **abstract);

private:
	int waitsocket(void);
	const char *commandline;

    int 				m_sock;
    LIBSSH2_SESSION*	m_session;

	int m_channelExitCode;
	static const int BUF_SIZE = 0x4000;
	std::string m_execResultStr;

	/*
	 1: Libssh2 initialization failed
	 2: Socket connect failed
	 3: Session init failed
	 4: Failure establishing SSH session
	 5: Authentication by password failed
	 6: Authentication by keyboard-interactive failed
	 7: Authentication by public key failed
	 8: No supported authentication methods found
	 9: Open channel failed
	 10: Exec command line Error
	 */
	int m_errCode;
	static char* ERR_MSG[];
	const char *keyfile1;
	const char *keyfile2;
};

#endif /* SSH2UTILS_H_ */
