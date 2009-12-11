TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .

CONFIG(debug, debug|release) {
	LIBS += log4cplusUD.lib
	DESTDIR = ../Debug
} else {
	LIBS += log4cplusU.lib
	DESTDIR = ../Release
}

SOURCES += main.cpp
TRANSLATIONS += testQt_cn.ts
