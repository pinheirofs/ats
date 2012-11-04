#include <QtCore>
#include <QApplication>

#include "guifactory.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    ats::display::GuiFactory *factory = ats::display::GuiFactory::getInstance();
    factory->showAtsMainWindow();

    return a.exec();
}
