TEMPLATE = lib
CONFIG += staticlib exceptions

HEADERS       = \
    wavedrawerslice.h \
    signalreal.h \
    dsphelper.h \
    irealsignal.h \
    mdrawertime.h \
    mdrawerfrequency.h \
    mdrawer.h \
    sliceotime.h \
    sliceofrequency.h \
    dspcontrol.h \
    uiwavetablemgrvue.h \
    blofeldwavetablemodel.h \
    blofeldwavetablemgrmodel.h \
    DefsWT.h
SOURCES       = \
    wavedrawerslice.cpp \
    signalreal.cpp \
    dsphelper.cpp \
    irealsignal.cpp \
    mdrawertime.cpp \
    mdrawerfrequency.cpp \
    mdrawer.cpp \
    sliceotime.cpp \
    sliceofrequency.cpp \
    dspcontrol.cpp \
    uiwavetablemgrvue.cpp \
    blofeldwavetablemodel.cpp \
    blofeldwavetablemgrmodel.cpp

symbian {
    TARGET.UID3 = 0xA000A64A
    include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
}
maemo5: include($$QT_SOURCE_TREE/examples/maemo5pkgrules.pri)

OTHER_FILES +=

