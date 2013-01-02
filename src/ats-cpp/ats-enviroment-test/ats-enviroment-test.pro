CONFIG += qtestlib
LIBS += ../ats-enviroment/libats-enviroment.so
PRE_TARGETDEPS += ../ats-enviroment/libats-enviroment.so
INCLUDEPATH += ../ats-enviroment
HEADERS += simulationtest.h
SOURCES += main-test.cpp \
    simulationtest.cpp
