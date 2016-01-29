TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    zprotocpp.cpp

HEADERS += zprotocpp.h \
    zproto_example.h

OTHER_FILES += \
    zprotocpp.gsl \
    zprotocpp.xml \
    zproto_codec_cpp.gsl \
    zproto_example.xml

INCLUDEPATH += \
    3rdparty/include

LIBS += -L/usr/local/lib

mac {
    PKG_CONFIG = /usr/local/bin/pkg-config
    QT_CONFIG -= no-pkg-config
}

CONFIG += link_pkgconfig
PKGCONFIG += libzmq
