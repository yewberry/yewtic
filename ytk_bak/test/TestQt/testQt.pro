TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += . ../../include/

CONFIG(debug, debug|release) {
	LIBS += ../../lib/log4cplusUD.lib
	DESTDIR = Debug
} else {
	LIBS += ../../lib/log4cplusU.lib
	DESTDIR = Release
}

SOURCES += main.cpp
TRANSLATIONS += testQt_cn.ts
