#include <qmessagebox.h>
#include <qmenubar.h>

#include "atsmainwindow.hpp"

namespace ats {
namespace display {

AtsMainWindow::AtsMainWindow(ApplicationController *controller) : controller(controller) {
    config();
    createMenus();
}

AtsMainWindow::~AtsMainWindow() {
    delete controller;
}

void AtsMainWindow::config() {
    setWindowTitle(tr("ATS - Air Traffic Simulation"));
    setMinimumSize(800, 600);
}
void AtsMainWindow::createMenus() {
    QMenuBar *menuBarInstance = menuBar();

//    QMenu *simulationMenu = menuBarInstance->addMenu("&Simulation");


    QMenu *systemMenu = menuBarInstance->addMenu("S&ystem");
    exitAction = new QAction(tr("&Exit"), this);
    systemMenu->addAction(exitAction);

}

void AtsMainWindow::closeEvent(QCloseEvent * event) {
    if (controller->isRunningSimulation()) {
        QMessageBox message(this);
        message.setWindowTitle(tr("Warning"));
        message.setText(tr("The simulation is running, do you want finsh it?"));
        message.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        message.setDefaultButton(QMessageBox::Yes);

        int option = message.exec();
        if (option == QMessageBox::Yes) {
            event->accept();
        } else {
            event->ignore();
        }
    }
    else {
        event->accept();
    }
}

void AtsMainWindow::notify() {

}

QAction *AtsMainWindow::getExitAction() {
    return exitAction;
}

} /* namespace display */
} /* namespace ats */
