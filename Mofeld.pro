QT       += core gui\

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = M
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++17 -fno-sized-deallocation


HEADERS     = \
    defs.h \
    client/Common/ctrlBasics/frmsynthctrl_rotary.h \
    client/Common/ctrlBasics/frmsynthctrl_sliderh.h \
    client/Common/ctrlBasics/frmsynthctrl_combobox.h \
    client/Common/ctrlBasics/frmsynthctrl_latchbutton.h \
    genericity/valuerange.h \
    genericity/valuemgr.h \
    genericity/icategorizable.h \
    genericity/entitydao.h \
    genericity/entity.h \
    genericity/synthenumelement.h \
    genericity/synthenum.h \
    genericity/BlofeldEnums.h \
    client/Common/ctrlBasics/CtrlsImport.h \
    BlofeldMgr/propriete.h \
    BlofeldMgr/patienteur.h \
    BlofeldMgr/parametre.h \
    BlofeldMgr/itagable.h \
    BlofeldMgr/instrument.h \
    BlofeldMgr/contrainteparametre.h \
    BlofeldMgr/blofeldreplica.h \
    BlofeldMgr/blofchannel.h \
    BlofeldMgr/arrangement.h \
    Messaging/wordwriter.h \
    Messaging/wordchecksum.h \
    Messaging/transaction.h \
    Messaging/sysexable.h \
    Messaging/requestwave.h \
    Messaging/requestmulti.h \
    Messaging/requestinstrument.h \
    Messaging/requestglobal.h \
    Messaging/replacer.h \
    Messaging/parametrecom.h \
    Messaging/messagewriter.h \
    Messaging/dumpwave.h \
    Messaging/dumpinstrument.h \
    Messaging/dumpglobal.h \
    Messaging/consequence.h \
    Messaging/bytemanager.h \
    Messaging/blofable.h \
    client/vues/blofeld/parts/frmfilter.h \
    client/vues/blofeld/parts/frmfilters.h \
    client/vues/blofeld/parts/frmfx.h \
    client/vues/blofeld/parts/frmlfo.h \
    client/vues/blofeld/parts/arpeggioslice.h \
    client/vues/blofeld/parts/arpegiocommon.h \
    client/vues/blofeld/parts/frmosc.h \
    client/vues/blofeld/parts/frmmodifier.h \
    client/vues/blofeld/parts/frmmatrixslice.h \
    client/vues/blofeld/parts/frmcommon.h \
    client/vues/edition/proprietevue.h \
    client/vues/edition/proprieteelementsvue.h \
    client/vues/edition/instrumentvue.h \
    client/vues/edition/easylist.h \
    client/vues/edition/draggable.h \
    client/vues/edition/arrangementvue.h \
    Midi/synthtransaction.h \
    Midi/miomgr.h \
    client/Models/proprietemodel.h \
    client/Models/instrumentmodel.h \
    client/Models/arrangementmodel.h \
    client/vues/guiBlofMainwindow.h \
    genericity/combotool.h \
    client/vues/edition/operationvue.h \
    client/vues/blofeldwindows.h \
    client/vues/blofeld/groups/frmmodifiers.h \
    client/vues/blofeld/groups/frmmatrix.h \
    client/vues/blofeld/groups/frmlfos.h \
    client/vues/blofeld/groups/frmgenerators.h \
    client/vues/blofeld/groups/frmfxs.h \
    client/vues/blofeld/groups/frmfilters.h \
    client/vues/blofeld/groups/frmenveloppes.h \
    client/vues/blofeld/groups/arpeggio.h \
    client/vues/blofeld/multi/blofeldmultivue.h \
    Messaging/dumpmulti.h \
    genericity/midiutility.h \
    client/vues/blofeld/multi/blofeldmultislice.h \
    client/vues/blofeldmultivue.h \
    client/Models/operationModel.h \
    BlofeldMgr/mixpropparams.h \
    client/Common/ctrlleaf.h \
    client/Common/ctrlcomponent.h \
    client/Common/ctrlcomposite.h \
    runguard.h \
    client/vues/edition/paramcontext.h \
    client/vues/parametrereaction.h \
    client/Common/ctrlvalueleaf.h \
    client/Common/ctrlparamleaf.h \
    wtDrawer_LIB/uiwavetablemgrvue.h \
    wtDrawer_LIB/signalreal.h \
    wtDrawer_LIB/mdrawertime.h \
    wtDrawer_LIB/mdrawerfrequency.h \
    wtDrawer_LIB/mdrawer.h \
    wtDrawer_LIB/irealsignal.h \
    wtDrawer_LIB/dsphelper.h \
    wtDrawer_LIB/dspcontrol.h \
    wtDrawer_LIB/DefsWT.h \
    wtDrawer_LIB/blofeldwavetablemodel.h \
    wtDrawer_LIB/blofeldwavetablemgrmodel.h \
    client/Models/wtmodel.h \
    client/vues/edition/wavetableselectvue.h \
    client/vues/blofeldpersistencevue.h \
    client/Common/ctrlBasics/imageprovider.h \
    client/vues/blofeldEditorVue.h \
    client/Common/keybordobs.h \
    wtDrawer_LIB/msoundprintervue.h \
    wtDrawer_LIB/mgeometry.h \
    wtDrawer_LIB/mcolorhelper.h \
    wtDrawer_LIB/mwavetableeditor.h \
    wtDrawer_LIB/mwteditorcommonview.h \
    timemaster.h \
    RtMidi.h


SOURCES     = \
              main.cpp \
    client/Common/ctrlBasics/frmsynthctrl_rotary.cpp \
    client/Common/ctrlBasics/frmsynthctrl_sliderh.cpp \
    client/Common/ctrlBasics/frmsynthctrl_combobox.cpp \
    client/Common/ctrlBasics/frmsynthctrl_latchbutton.cpp \
    genericity/valuerange.cpp \
    genericity/valuemgr.cpp \
    genericity/icategorizable.cpp \
    genericity/entity.cpp \
    genericity/synthenumelement.cpp \
    genericity/synthenum.cpp \
    genericity/BlofeldEnums.cpp \
    BlofeldMgr/propriete.cpp \
    BlofeldMgr/patienteur.cpp \
    BlofeldMgr/parametre.cpp \
    BlofeldMgr/itagable.cpp \
    BlofeldMgr/instrument.cpp \
    BlofeldMgr/contrainteparametre.cpp \
    BlofeldMgr/blofeldreplica.cpp \
    BlofeldMgr/blofchannel.cpp \
    BlofeldMgr/arrangement.cpp \
    Messaging/wordwriter.cpp \
    Messaging/wordchecksum.cpp \
    Messaging/transaction.cpp \
    Messaging/sysexable.cpp \
    Messaging/requestwave.cpp \
    Messaging/requestmulti.cpp \
    Messaging/requestinstrument.cpp \
    Messaging/requestglobal.cpp \
    Messaging/replacer.cpp \
    Messaging/parametrecom.cpp \
    Messaging/messagewriter.cpp \
    Messaging/dumpwave.cpp \
    Messaging/dumpinstrument.cpp \
    Messaging/dumpglobal.cpp \
    Messaging/consequence.cpp \
    Messaging/bytemanager.cpp \
    Messaging/blofable.cpp \
    client/vues/edition/proprietevue.cpp \
    client/vues/edition/proprieteelementsvue.cpp \
    client/vues/edition/instrumentvue.cpp \
    client/vues/edition/easylist.cpp \
    client/vues/edition/draggable.cpp \
    client/vues/edition/arrangementvue.cpp \
    Midi/synthtransaction.cpp \
    Midi/miomgr.cpp \
    client/Models/proprietemodel.cpp \
    client/Models/instrumentmodel.cpp \
    client/Models/arrangementmodel.cpp \
    client/vues/guiBlofMainwindow.cpp \
    client/vues/blofeldEditorVue.cpp \
    client/vues/edition/operationvue.cpp \
    client/Models/blofeldcommonmodel.cpp \
    client/vues/blofeldwindows.cpp \
    client/vues/blofeld/parts/frmosc.cpp \
    client/vues/blofeld/parts/frmmodifier.cpp \
    client/vues/blofeld/parts/frmmatrixslice.cpp \
    client/vues/blofeld/parts/frmlfo.cpp \
    client/vues/blofeld/parts/frmfx.cpp \
    client/vues/blofeld/parts/frmfilter.cpp \
    client/vues/blofeld/parts/frmenveloppe.cpp \
    client/vues/blofeld/parts/frmcommon.cpp \
    client/vues/blofeld/parts/arpegiocommon.cpp \
    client/vues/blofeld/parts/arpeggioslice.cpp \
    client/vues/blofeld/groups/frmmodifiers.cpp \
    client/vues/blofeld/groups/frmmatrix.cpp \
    client/vues/blofeld/groups/frmlfos.cpp \
    client/vues/blofeld/groups/frmgenerators.cpp \
    client/vues/blofeld/groups/frmfxs.cpp \
    client/vues/blofeld/groups/frmfilters.cpp \
    client/vues/blofeld/groups/frmenveloppes.cpp \
    client/vues/blofeld/groups/arpeggio.cpp \
    Messaging/dumpmulti.cpp \
    genericity/midiutility.cpp \
    client/vues/blofeld/multi/blofeldmultislice.cpp \
    client/vues/blofeldmultivue.cpp \
    BlofeldMgr/mixpropparams.cpp \
    client/Common/ctrlcomposite.cpp \
    client/Common/ctrlcomponent.cpp \
    runguard.cpp \
    client/vues/edition/paramcontext.cpp \
    client/Common/ctrlvalueleaf.cpp \
    client/Common/ctrlparamleaf.cpp \
    wtDrawer_LIB/uiwavetablemgrvue.cpp \
    wtDrawer_LIB/signalreal.cpp \
    wtDrawer_LIB/mdrawertime.cpp \
    wtDrawer_LIB/mdrawerfrequency.cpp \
    wtDrawer_LIB/mdrawer.cpp \
    wtDrawer_LIB/irealsignal.cpp \
    wtDrawer_LIB/dsphelper.cpp \
    wtDrawer_LIB/dspcontrol.cpp \
    wtDrawer_LIB/blofeldwavetablemodel.cpp \
    wtDrawer_LIB/blofeldwavetablemgrmodel.cpp \
    client/Models/wtmodel.cpp \
    client/vues/edition/wavetableselectvue.cpp \
    client/vues/blofeldpersistencevue.cpp \
    client/Common/ctrlBasics/imageprovider.cpp \
    client/Common/keybordobs.cpp \
    wtDrawer_LIB/msoundprintervue.cpp \
    wtDrawer_LIB/mgeometry.cpp \
    wtDrawer_LIB/mcolorhelper.cpp \
    wtDrawer_LIB/mwavetableeditor.cpp \
    wtDrawer_LIB/mwteditorcommonview.cpp \
    timemaster.cpp \
    RtMidi.cpp



CONFIG += static
CONFIG += exceptions

DEFINES +=  LITTLE_ENDIAN

#sources.path = $$[MOFELD]
#INSTALLS += target



OTHER_FILES += \
    qss/pagefold.qss \
    qss/default.qss \
    qss/coffee.qss

RESOURCES += \
    stylesheet.qrc \

#DESTDIR = ../mout2_exe
#OBJECTS_DIR = ../mout2
#MOC_DIR = ../mout2

#DEPENDPATH += . ../wtDrawer_LIB/
#INCLUDEPATH += ../wtDrawer_LIB/
#LIBS +=  ../_LIBS/wtDraw/debug/libWTDrawer.a \
#  ../_LIBS/wtDraw/release/libWTDrawer.a
