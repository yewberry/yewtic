TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .

win32:debug {
message(in debug $$DEFINES)
	LIBS += log4cplusUD.lib
	DESTDIR = ../Debug
} else {
message("in release")
	LIBS += log4cplusU.lib
	DESTDIR = ../Release
}

SOURCES += main.cpp
TRANSLATIONS += testQt_cn.ts