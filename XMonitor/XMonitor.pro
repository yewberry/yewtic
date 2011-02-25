TEMPLATE = app
TARGET = XMonitor
QT += core \
    gui \
    sql \
    network \
    opengl \
    webkit \
    script
HEADERS += src/Common.h \
    src/TopHeader.h \
    src/XMonitor.h
SOURCES += src/Common.cpp \
    src/TopHeader.cpp \
    src/XMonitor.cpp \
    src/main.cpp
FORMS += ui/XMonitor.ui
RESOURCES += res.qrc
