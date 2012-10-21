#include <QtCore>
#include <QApplication>

#include "guifactory.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    ats::display::GuiFactory *factory = ats::display::GuiFactory::getInstance();
    factory->showAtsMainWindow(0);

    return a.exec();
}
