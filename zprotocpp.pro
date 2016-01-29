TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
PRE_TARGETDEPS += zproto_example.h

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

cpp_proto.target = zproto_example.h
cpp_proto.commands = /usr/local/bin/gsl -script:zproto_codec_cpp zproto_example.xml
cpp_proto.depends = c_proto

c_proto.target = czproto_example.h
c_proto.commands = /usr/local/bin/gsl -script:/usr/local/bin/zproto_codec_c.gsl zproto_example.xml && mv zproto_example.h czproto_example.h

QMAKE_EXTRA_TARGETS += c_proto cpp_proto
