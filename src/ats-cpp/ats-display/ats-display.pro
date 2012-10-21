TEMPLATE = app
TARGET = ats-display
QT += core \
    gui
HEADERS += atsmainwindow.hpp \
    applicationcontroller.hpp \
    application.hpp \
    observer.hpp \
    observable.hpp \
    guifactory.hpp
SOURCES += observer.cpp \
    atsmainwindow.cpp \
    applicationcontroller.cpp \
    application.cpp \
    observable.cpp \
    guifactory.cpp \
    main.cpp
FORMS +=
RESOURCES +=
