TEMPLATE = app
TARGET = XMonitor
QT += core \
    gui \
    sql \
    network \
    opengl \
    webkit \
    script
HEADERS += src/MyQtLog.h \
    src/Server.h \
    src/Common.h \
    src/TopHeader.h \
    src/XMonitor.h
SOURCES += src/MyQtLog.cpp \
    src/Server.cpp \
    src/Common.cpp \
    src/TopHeader.cpp \
    src/XMonitor.cpp \
    src/main.cpp
FORMS += ui/MyQtLog.ui \
    ui/XMonitor.ui
RESOURCES += res.qrc
