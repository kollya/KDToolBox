SOURCES += $$PWD/src/messagehandler.cpp
HEADERS += $$PWD/src/messagehandler.h

INCLUDEPATH += $$PWD/src/

DEFINES += \
    QT_NO_CAST_FROM_ASCII \
    QT_USE_STRINGBUILDER \
    QT_DEPRECATED_WARNINGS \
    QT_DISABLE_DEPRECATED_BEFORE=0x051200 \
