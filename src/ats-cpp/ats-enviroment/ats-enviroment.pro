TEMPLATE = lib
QT -= gui
TARGET = ats-enviroment
DEFINES += ATSENVIROMENT_LIBRARY
HEADERS += typedefs.h \
    typedefs.h \
    coordinate.h \
    streachcalculator.h \
    stretch.h \
    converter.h \
    aircraftfactory.h \
    aircraft.h \
    simulationlistener.h \
    simulation.h \
    routepoint.h \
    traffic.h
SOURCES += coordinate.cpp \
    streachcalculator.cpp \
    stretch.cpp \
    converter.cpp \
    aircraftfactory.cpp \
    aircraft.cpp \
    simulationlistener.cpp \
    simulation.cpp \
    routepoint.cpp \
    traffic.cpp
LIBS += -lm
