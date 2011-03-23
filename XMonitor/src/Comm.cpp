/*
 * Comm.cpp
 *
 *  Created on: 2011-2-25
 *      Author: Yewberry
 */

#include "Comm.h"
#include <iostream>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/algorithm/string.hpp>

QString Comm::stringFromResource(const QString &resName) {
	QFile file(resName);
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream ts(&file);
	return ts.readAll();
}

std::string Comm::uuid(){
	boost::uuids::random_generator uuid_gen;
	boost::uuids::uuid uu = uuid_gen();
	std::string str = boost::uuids::to_string(uu);
	boost::erase_all(str, "-");

	return str;
}

QMutex Comm::SVR_REC_MUTEX;
