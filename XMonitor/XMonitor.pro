TEMPLATE = app
TARGET = XMonitor
QT += core \
    gui \
    sql \
    network \
    opengl \
    webkit \
    script
HEADERS += src/StepModel.h \
    src/XModel.h \
    src/ReportView.h \
    src/SSH2Utils.h \
    src/CodeEditor.h \
    src/StepScriptDialog.h \
    src/JsHighlighter.h \
    src/StepForm.h \
    src/XThread.h \
    src/ServerThread.h \
    src/ServerViewItem.h \
    src/ServerForm.h \
    src/TitleBar.h \
    src/ServerViewLink.h \
    src/ServerViewNode.h \
    src/ServerView.h \
    src/Comm.h \
    src/MyQtLog.h \
    src/TopHeader.h \
    src/XMonitor.h
SOURCES += src/StepModel.cpp \
    src/XModel.cpp \
    src/ReportView.cpp \
    src/SSH2Utils.cpp \
    src/CodeEditor.cpp \
    src/StepScriptDialog.cpp \
    src/JsHighlighter.cpp \
    src/StepForm.cpp \
    src/XThread.cpp \
    src/ServerThread.cpp \
    src/ServerViewItem.cpp \
    src/ServerForm.cpp \
    src/TitleBar.cpp \
    src/ServerViewLink.cpp \
    src/ServerViewNode.cpp \
    src/ServerView.cpp \
    src/Comm.cpp \
    src/MyQtLog.cpp \
    src/TopHeader.cpp \
    src/XMonitor.cpp \
    src/main.cpp
FORMS += ui/ReportView.ui \
    ui/ServerForm.ui \
    ui/StepForm.ui \
    ui/StepScriptDialog.ui \
    ui/StepScriptDialog.ui \
    ui/StepForm.ui \
    ui/ServerForm.ui \
    ui/MyQtLog.ui \
    ui/XMonitor.ui
RESOURCES += res.qrc
INCLUDEPATH += D:/yewberry/boost_1_45_0 \
    C:/MinGW/include \
    C:/MinGW/lib/gcc/mingw32/4.5.2/include \
    C:/MinGW/lib/gcc/mingw32/4.5.2/include-fixed \
    C:/MinGW/lib/gcc/mingw32/4.5.2/include/c++ \
    C:/MinGW/lib/gcc/mingw32/4.5.2/include/c++/mingw32 \
    C:/MinGW/lib/gcc/mingw32/4.5.2/include/c++/backward \
    ../TestLibssh2/lib/include
LIBS += -L../TestLibssh2/lib \
    -lpthread \
    -lwsock32 \
    -lssh2dll
