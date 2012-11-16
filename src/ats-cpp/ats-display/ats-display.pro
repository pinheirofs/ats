TEMPLATE = app
TARGET = ats-display
QT += core \
    gui
LIBS += ../ats-enviroment/libats-enviroment.so
PRE_TARGETDEPS += ../ats-enviroment/libats-enviroment.so
INCLUDEPATH += ../ats-enviroment
HEADERS += trafficvalidator.h \
    airtrafficdialog.h \
    airtrafficcontroller.h \
    guifactory.h \
    atsmainwindow.h \
    applicationcontroller.h \
    application.h
SOURCES += trafficvalidator.cpp \
    airtrafficdialog.cpp \
    airtrafficcontroller.cpp \
    atsmainwindow.cpp \
    applicationcontroller.cpp \
    application.cpp \
    guifactory.cpp \
    main.cpp
FORMS +=
RESOURCES +=
