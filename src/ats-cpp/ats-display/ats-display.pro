TEMPLATE = app
TARGET = ats-display
QT += core \
    gui
LIBS += ../ats-enviroment/libats-enviroment.so
PRE_TARGETDEPS += ../ats-enviroment/libats-enviroment.so
INCLUDEPATH += ../ats-enviroment
HEADERS += guifactory.h \
    atsmainwindow.h \
    applicationcontroller.h \
    application.h \
    airtrafficmanagementdialog.h \
    airtrafficmanagementcontroller.h
SOURCES += airtrafficmanagementdialog.cpp \
    airtrafficmanagementcontroller.cpp \
    atsmainwindow.cpp \
    applicationcontroller.cpp \
    application.cpp \
    guifactory.cpp \
    main.cpp
FORMS +=
RESOURCES +=
