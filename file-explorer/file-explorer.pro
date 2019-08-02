
# build an application
TEMPLATE = app

# use the core module and do not use the gui module
QT       += core
QT       += gui
QT       += widgets

# name of the executable
TARGET = file-explorer

# allow console output
CONFIG   += console

# for mac remove the application bundling
macx {
    CONFIG   -= app_bundle
}

HEADERS += window.h

SOURCES += main.cpp window.cpp readvtu.cpp

INCLUDEPATH += /usr/local/include/vtk-7.0 

LIBS += -L /usr/local/lib      \
        -lvtkCommonCore-7.0d   \
        -lvtkIOCore-7.0d       \
        -lvtkIOXML-7.0d

