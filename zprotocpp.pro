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

LIBS += \
    -L$$PWD/3rdparty/lib -lzmq
