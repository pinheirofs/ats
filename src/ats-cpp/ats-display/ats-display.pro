TEMPLATE = app
TARGET = ats-display
QT += core \
    gui
HEADERS += airtrafficmanagementdialog.hpp \
    airtrafficmanagementcontroller.hpp \
    atsmainwindow.hpp \
    applicationcontroller.hpp \
    application.hpp \
    observer.hpp \
    observable.hpp \
    guifactory.hpp
SOURCES += airtrafficmanagementdialog.cpp \
    airtrafficmanagementcontroller.cpp \
    observer.cpp \
    atsmainwindow.cpp \
    applicationcontroller.cpp \
    application.cpp \
    observable.cpp \
    guifactory.cpp \
    main.cpp
FORMS +=
RESOURCES +=
