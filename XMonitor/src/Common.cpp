/*
 * Common.cpp
 *
 *  Created on: 2011-2-25
 *      Author: Yewberry
 */

#include "Common.h"

QString Common::stringFromResource(const QString &resName) {
	QFile file(resName);
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream ts(&file);
	return ts.readAll();
}
