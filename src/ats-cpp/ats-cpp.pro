TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS =  ats-display \
    ats-enviroment \
    ats-enviroment-test

ats-display.depends = ats-enviroment
ats-enviroment-test.depends = ats-enviroment