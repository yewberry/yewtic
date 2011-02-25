/*
 * main.cpp
 *
 *  Created on: 2011-2-25
 *      Author: Yewberry
 */

#include <iostream>
#include <string>
#include "SSH2Utils.h"

int main(int argc, char* argv[]) {
	SSH2Utils ssh2;
	ssh2.init();

	int rc = 0;
	rc = ssh2.connect(argv[1], argv[2], argv[3]);

	if(rc == 0){
		char *t = "ls -l";
		rc = ssh2.exec(t);
		std::string str = ssh2.execResultStr();
		std::cout << "CMD RESULT:\n" << str << std::endl;
	}
	return 0;

}
