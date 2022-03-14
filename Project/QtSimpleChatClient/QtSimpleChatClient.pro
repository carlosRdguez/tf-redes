QT += core network gui widgets

TARGET = QtSimpleChatClient
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += debug_and_release

SOURCES += \
    clientmain.cpp \
    chatwindow.cpp \
    chatclient.cpp

FORMS += \
    chatwindow.ui

HEADERS += \
    chatwindow.h \
    chatclient.h

include($$PWD/../Qt-Secret/Qt-Secret.pri)

win32:RC_ICONS += cryptochat.ico
