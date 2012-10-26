#include <qmessagebox.h>
#include <qmenubar.h>

#include "atsmainwindow.hpp"

namespace ats {
namespace display {

AtsMainWindow::AtsMainWindow(ApplicationController *controller)
        : controller(controller) {
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

    QMenu *simulationMenu = menuBarInstance->addMenu("&Air Traffic");
    airTraficManagementAction = new QAction(tr("&Management"), this);
    simulationMenu->addAction(airTraficManagementAction);

    QMenu *systemMenu = menuBarInstance->addMenu("S&ystem");
    exitAction = new QAction(tr("&Exit"), this);
    systemMenu->addAction(exitAction);

}

/* SLOTs methods */

void AtsMainWindow::closeEvent(QCloseEvent * event) {
    if (controller->isRunningSimulation()) {
        int option = QMessageBox::question(this, tr("Warning"), tr("The simulation is running, do you want finsh it?"),
                QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

        if (option == QMessageBox::Yes) {
            event->accept();
        }
        else {
            event->ignore();
        }
    }
    else {
        event->accept();
    }
}

void AtsMainWindow::notify() {

}

/* getter/ssetter methods */

QAction *AtsMainWindow::getExitAction() {
    return exitAction;
}

QAction *AtsMainWindow::getAirTrafficManagementAction() {
    return airTraficManagementAction;
}

} /* namespace display */
} /* namespace ats */
