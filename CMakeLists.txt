cmake_minimum_required(VERSION 3.5)

project(MOFELD VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)


include(FetchContent)
FetchContent_Declare(rtmidi
  GIT_REPOSITORY "https://github.com/hyper-temporal/rtmidi.git"
  GIT_TAG "origin/main"   # it's much better to use a specific Git revision or Git tag for reproducibility
  SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/rtmidi"
)
FetchContent_MakeAvailable(rtmidi)
FetchContent_Declare(rtaudio
  GIT_REPOSITORY "https://github.com/hyper-temporal/rtaudio.git"
  GIT_TAG "origin/main"   # it's much better to use a specific Git revision or Git tag for reproducibility
  SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/rtaudio"
)
FetchContent_MakeAvailable(rtaudio)


if(UNIX AND NOT APPLE)
  include(FindAlsa)
  FindAlsa()
  find_path(ALSA_INCLUDE_DIR NAMES asoundlib.h
            PATH_SUFFIXES alsa
            DOC "The ALSA (asound) include directory"
  )

  find_library(ALSA_LIBRARY NAMES asound
            DOC "The ALSA (asound) library"
  )

  # handle the QUIETLY and REQUIRED arguments and set ALSA_FOUND to TRUE if
  # all listed variables are TRUE
  include("${CMAKE_CURRENT_LIST_DIR}/FindPackageHandleStandardArgs.cmake")
  FIND_PACKAGE_HANDLE_STANDARD_ARGS(ALSA DEFAULT_MSG ALSA_LIBRARY ALSA_INCLUDE_DIR)

  if(ALSA_FOUND)
    set( ALSA_LIBRARIES ${ALSA_LIBRARY} )
    set( ALSA_INCLUDE_DIRS ${ALSA_INCLUDE_DIR} )
  endif()

  mark_as_advanced(ALSA_INCLUDE_DIR ALSA_LIBRARY)


endif()


include_directories(
    MOFELD_PORTABLE/include
)

set(PROJECT_SOURCES

    MOFELD_PORTABLE/include/arpeggio.h
    MOFELD_PORTABLE/include/arpeggioslice.h
    MOFELD_PORTABLE/include/arpegiocommon.h
    MOFELD_PORTABLE/include/arrangement.h
    MOFELD_PORTABLE/include/arrangementmodel.h
    MOFELD_PORTABLE/include/arrangementvue.h
    MOFELD_PORTABLE/include/blofable.h
    MOFELD_PORTABLE/include/blofchannel.h
    MOFELD_PORTABLE/include/blofeldEditorVue.h
    MOFELD_PORTABLE/include/BlofeldEnums.h
    MOFELD_PORTABLE/include/blofeldmultislice.h
    MOFELD_PORTABLE/include/blofeldmultivue.h
    MOFELD_PORTABLE/include/blofeldpersistencevue.h
    MOFELD_PORTABLE/include/blofeldreplica.h
    MOFELD_PORTABLE/include/blofeldwavetablemgrmodel.h
    MOFELD_PORTABLE/include/blofeldwavetablemodel.h
    MOFELD_PORTABLE/include/blofeldwindows.h
    MOFELD_PORTABLE/include/bufferspec.h
    MOFELD_PORTABLE/include/bytemanager.h
    MOFELD_PORTABLE/include/combotool.h
    MOFELD_PORTABLE/include/consequence.h
    MOFELD_PORTABLE/include/contrainteparametre.h
    MOFELD_PORTABLE/include/ctrlcomponent.h
    MOFELD_PORTABLE/include/ctrlcomposite.h
    MOFELD_PORTABLE/include/ctrlleaf.h
    MOFELD_PORTABLE/include/ctrlparamleaf.h
    MOFELD_PORTABLE/include/CtrlsImport.h
    MOFELD_PORTABLE/include/ctrlvalueleaf.h
    MOFELD_PORTABLE/include/defs.h
    MOFELD_PORTABLE/include/DefsWT.h
    MOFELD_PORTABLE/include/draggable.h
    MOFELD_PORTABLE/include/dspcontrol.h
    MOFELD_PORTABLE/include/dsphelper.h
    MOFELD_PORTABLE/include/dumpglobal.h
    MOFELD_PORTABLE/include/dumpinstrument.h
    MOFELD_PORTABLE/include/dumpmulti.h
    MOFELD_PORTABLE/include/dumpwave.h
    MOFELD_PORTABLE/include/easylist.h
    MOFELD_PORTABLE/include/entity.h
    MOFELD_PORTABLE/include/entitydao.h
    MOFELD_PORTABLE/include/frmcommon.h
    MOFELD_PORTABLE/include/frmenveloppe.h
    MOFELD_PORTABLE/include/frmenveloppes.h
    MOFELD_PORTABLE/include/frmfilter.h
    MOFELD_PORTABLE/include/frmfilters.h
    MOFELD_PORTABLE/include/frmfx.h
    MOFELD_PORTABLE/include/frmfxs.h
    MOFELD_PORTABLE/include/frmgenerators.h
    MOFELD_PORTABLE/include/frmlfo.h
    MOFELD_PORTABLE/include/frmlfos.h
    MOFELD_PORTABLE/include/frmmatrix.h
    MOFELD_PORTABLE/include/frmmatrixslice.h
    MOFELD_PORTABLE/include/frmmodifier.h
    MOFELD_PORTABLE/include/frmmodifiers.h
    MOFELD_PORTABLE/include/frmosc.h
    MOFELD_PORTABLE/include/frmsynthctrl_combobox.h
    MOFELD_PORTABLE/include/frmsynthctrl_latchbutton.h
    MOFELD_PORTABLE/include/frmsynthctrl_rotary.h
    MOFELD_PORTABLE/include/frmsynthctrl_sliderh.h
    MOFELD_PORTABLE/include/guiBlofMainwindow.h
    MOFELD_PORTABLE/include/icategorizable.h
    MOFELD_PORTABLE/include/imageprovider.h
    MOFELD_PORTABLE/include/instrument.h
    MOFELD_PORTABLE/include/instrumentmodel.h
    MOFELD_PORTABLE/include/instrumentvue.h
    MOFELD_PORTABLE/include/irealsignal.h
    MOFELD_PORTABLE/include/itagable.h
    MOFELD_PORTABLE/include/keybordobs.h
    MOFELD_PORTABLE/include/mcolorhelper.h
    MOFELD_PORTABLE/include/mdrawer.h
    MOFELD_PORTABLE/include/mdrawerfrequency.h
    MOFELD_PORTABLE/include/mdrawertime.h
    MOFELD_PORTABLE/include/messagewriter.h
    MOFELD_PORTABLE/include/mgeometry.h
    MOFELD_PORTABLE/include/midiutility.h
    MOFELD_PORTABLE/include/miomgr.h
    MOFELD_PORTABLE/include/mixpropparams.h
    MOFELD_PORTABLE/include/msoundprintervue.h
    MOFELD_PORTABLE/include/targetprovider.h
    MOFELD_PORTABLE/include/operationModel.h
    MOFELD_PORTABLE/include/operationvue.h
    MOFELD_PORTABLE/include/paramcontext.h
    MOFELD_PORTABLE/include/parametre.h
    MOFELD_PORTABLE/include/parametrecom.h
    MOFELD_PORTABLE/include/parametrereaction.h
    MOFELD_PORTABLE/include/patienteur.h
    MOFELD_PORTABLE/include/propriete.h
    MOFELD_PORTABLE/include/proprieteelementsvue.h
    MOFELD_PORTABLE/include/proprietemodel.h
    MOFELD_PORTABLE/include/proprietevue.h
    MOFELD_PORTABLE/include/replacer.h
    MOFELD_PORTABLE/include/requestglobal.h
    MOFELD_PORTABLE/include/requestinstrument.h
    MOFELD_PORTABLE/include/requestmulti.h
    MOFELD_PORTABLE/include/requestwave.h
    MOFELD_PORTABLE/include/runguard.h
    MOFELD_PORTABLE/include/signalreal.h
    MOFELD_PORTABLE/include/synthenum.h
    MOFELD_PORTABLE/include/synthenumelement.h
    MOFELD_PORTABLE/include/synthtransaction.h
    MOFELD_PORTABLE/include/sysexable.h
    MOFELD_PORTABLE/include/tagvue.h
    MOFELD_PORTABLE/include/timemaster.h
    MOFELD_PORTABLE/include/transaction.h
    MOFELD_PORTABLE/include/uiwavetablemgrvue.h
    MOFELD_PORTABLE/include/valuemgr.h
    MOFELD_PORTABLE/include/valuerange.h
    MOFELD_PORTABLE/include/wavetableselectvue.h
    MOFELD_PORTABLE/include/wordchecksum.h
    MOFELD_PORTABLE/include/wordwriter.h
    MOFELD_PORTABLE/include/wtmodel.h




    MOFELD_PORTABLE/src/main.cpp
    MOFELD_PORTABLE/src/arpeggio.cpp
    MOFELD_PORTABLE/src/arpeggioslice.cpp
    MOFELD_PORTABLE/src/arpegiocommon.cpp
    MOFELD_PORTABLE/src/arrangement.cpp
    MOFELD_PORTABLE/src/arrangementmodel.cpp
    MOFELD_PORTABLE/src/arrangementvue.cpp
    MOFELD_PORTABLE/src/blofable.cpp
    MOFELD_PORTABLE/src/blofchannel.cpp
    MOFELD_PORTABLE/src/blofeldcommonmodel.cpp
    MOFELD_PORTABLE/src/blofeldEditorVue.cpp
    MOFELD_PORTABLE/src/BlofeldEnums.cpp
    MOFELD_PORTABLE/src/blofeldmultislice.cpp
    MOFELD_PORTABLE/src/blofeldmultivue.cpp
    MOFELD_PORTABLE/src/blofeldpersistencevue.cpp
    MOFELD_PORTABLE/src/blofeldreplica.cpp
    MOFELD_PORTABLE/src/blofeldwavetablemgrmodel.cpp
    MOFELD_PORTABLE/src/blofeldwavetablemodel.cpp
    MOFELD_PORTABLE/src/blofeldwindows.cpp
    MOFELD_PORTABLE/src/bufferspec.cpp
    MOFELD_PORTABLE/src/bytemanager.cpp
    MOFELD_PORTABLE/src/consequence.cpp
    MOFELD_PORTABLE/src/contrainteparametre.cpp
    MOFELD_PORTABLE/src/ctrlcomponent.cpp
    MOFELD_PORTABLE/src/ctrlcomposite.cpp
    MOFELD_PORTABLE/src/ctrlparamleaf.cpp
    MOFELD_PORTABLE/src/ctrlvalueleaf.cpp
    MOFELD_PORTABLE/src/draggable.cpp
    MOFELD_PORTABLE/src/dspcontrol.cpp
    MOFELD_PORTABLE/src/dsphelper.cpp
    MOFELD_PORTABLE/src/dumpglobal.cpp
    MOFELD_PORTABLE/src/dumpinstrument.cpp
    MOFELD_PORTABLE/src/dumpmulti.cpp
    MOFELD_PORTABLE/src/dumpwave.cpp
    MOFELD_PORTABLE/src/easylist.cpp
    MOFELD_PORTABLE/src/entity.cpp
    MOFELD_PORTABLE/src/frmcommon.cpp
    MOFELD_PORTABLE/src/frmenveloppe.cpp
    MOFELD_PORTABLE/src/frmenveloppes.cpp
    MOFELD_PORTABLE/src/frmfilter.cpp
    MOFELD_PORTABLE/src/frmfilters.cpp
    MOFELD_PORTABLE/src/frmfx.cpp
    MOFELD_PORTABLE/src/frmfxs.cpp
    MOFELD_PORTABLE/src/frmgenerators.cpp
    MOFELD_PORTABLE/src/frmlfo.cpp
    MOFELD_PORTABLE/src/frmlfos.cpp
    MOFELD_PORTABLE/src/frmmatrix.cpp
    MOFELD_PORTABLE/src/frmmatrixslice.cpp
    MOFELD_PORTABLE/src/frmmodifier.cpp
    MOFELD_PORTABLE/src/frmmodifiers.cpp
    MOFELD_PORTABLE/src/frmosc.cpp
    MOFELD_PORTABLE/src/frmsynthctrl_combobox.cpp
    MOFELD_PORTABLE/src/frmsynthctrl_latchbutton.cpp
    MOFELD_PORTABLE/src/frmsynthctrl_rotary.cpp
    MOFELD_PORTABLE/src/frmsynthctrl_sliderh.cpp
    MOFELD_PORTABLE/src/guiBlofMainwindow.cpp
    MOFELD_PORTABLE/src/icategorizable.cpp
    MOFELD_PORTABLE/src/imageprovider.cpp
    MOFELD_PORTABLE/src/instrument.cpp
    MOFELD_PORTABLE/src/instrumentmodel.cpp
    MOFELD_PORTABLE/src/instrumentvue.cpp
    MOFELD_PORTABLE/src/irealsignal.cpp
    MOFELD_PORTABLE/src/itagable.cpp
    MOFELD_PORTABLE/src/keybordobs.cpp
    MOFELD_PORTABLE/src/mcolorhelper.cpp
    MOFELD_PORTABLE/src/mdrawer.cpp
    MOFELD_PORTABLE/src/mdrawerfrequency.cpp
    MOFELD_PORTABLE/src/mdrawertime.cpp
    MOFELD_PORTABLE/src/messagewriter.cpp
    MOFELD_PORTABLE/src/mgeometry.cpp
    MOFELD_PORTABLE/src/midiutility.cpp
    MOFELD_PORTABLE/src/miomgr.cpp
    MOFELD_PORTABLE/src/mixpropparams.cpp
    MOFELD_PORTABLE/src/msoundprintervue.cpp
    MOFELD_PORTABLE/src/operationvue.cpp
    MOFELD_PORTABLE/src/paramcontext.cpp
    MOFELD_PORTABLE/src/parametre.cpp
    MOFELD_PORTABLE/src/parametrecom.cpp
    MOFELD_PORTABLE/src/patienteur.cpp
    MOFELD_PORTABLE/src/propriete.cpp
    MOFELD_PORTABLE/src/proprieteelementsvue.cpp
    MOFELD_PORTABLE/src/proprietemodel.cpp
    MOFELD_PORTABLE/src/proprietevue.cpp
    MOFELD_PORTABLE/src/replacer.cpp
    MOFELD_PORTABLE/src/requestglobal.cpp
    MOFELD_PORTABLE/src/requestinstrument.cpp
    MOFELD_PORTABLE/src/requestmulti.cpp
    MOFELD_PORTABLE/src/requestwave.cpp
    MOFELD_PORTABLE/src/runguard.cpp
    MOFELD_PORTABLE/src/signalreal.cpp
    MOFELD_PORTABLE/src/synthenum.cpp
    MOFELD_PORTABLE/src/synthenumelement.cpp
    MOFELD_PORTABLE/src/synthtransaction.cpp
    MOFELD_PORTABLE/src/sysexable.cpp
    MOFELD_PORTABLE/src/tagvue.cpp
    MOFELD_PORTABLE/src/timemaster.cpp
    MOFELD_PORTABLE/src/transaction.cpp
    MOFELD_PORTABLE/src/uiwavetablemgrvue.cpp
    MOFELD_PORTABLE/src/valuemgr.cpp
    MOFELD_PORTABLE/src/valuerange.cpp
    MOFELD_PORTABLE/src/wavetableselectvue.cpp
    MOFELD_PORTABLE/src/wordchecksum.cpp
    MOFELD_PORTABLE/src/wordwriter.cpp
    MOFELD_PORTABLE/src/wtmodel.cpp


)



if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MofeldApp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET MofeldApp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(MofeldApp SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(MofeldApp
            ${PROJECT_SOURCES}
        )
    endif()
endif()



target_link_libraries(MofeldApp PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    rtaudio
    rtmidi
)

set_target_properties(MofeldApp PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER mofeld.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS MofeldApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})



if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MofeldApp)
endif()





