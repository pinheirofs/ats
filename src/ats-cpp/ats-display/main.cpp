#include <QtCore>
#include <QApplication>

#include "guifactory.h"

void initLog();

int main(int argc, char *argv[]) {
    initLog();

    QApplication a(argc, argv);

    ats::display::GuiFactory *factory = ats::display::GuiFactory::getInstance();
    factory->showAtsMainWindow();

    return a.exec();
}

void initLog() {

}
