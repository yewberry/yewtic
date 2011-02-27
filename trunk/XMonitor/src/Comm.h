/*
 * Comm.h
 *
 *  Created on: 2011-2-25
 *      Author: Yewberry
 */

#ifndef COMM_H_
#define COMM_H_

#include <QtCore>
#include <string>
#include "MyQtLog.h"

class Comm {
public:
	static QString stringFromResource(const QString &resName);
	static std::string uuid();

};

#endif /* COMM_H_ */
