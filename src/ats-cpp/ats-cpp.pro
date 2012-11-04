TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS = ats-enviroment \
    ats-display

ats-display.depends = ats-enviroment