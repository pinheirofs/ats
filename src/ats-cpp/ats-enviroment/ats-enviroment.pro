TEMPLATE = lib
QT -= gui
TARGET = ats-enviroment
DEFINES += ATSENVIROMENT_LIBRARY
HEADERS += aircraft.h \
    simulationlistener.h \
    simulation.h \
    routepoint.h \
    traffic.h
SOURCES += aircraft.cpp \
    simulationlistener.cpp \
    simulation.cpp \
    routepoint.cpp \
    traffic.cpp
