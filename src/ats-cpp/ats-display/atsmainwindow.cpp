#include <qmessagebox.h>
#include <qmenubar.h>

#include "atsmainwindow.h"

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
    addAirTraficAction = new QAction(tr("&Add"), this);
    simulationMenu->addAction(addAirTraficAction);
    connect(addAirTraficAction, SIGNAL(triggered()), this, SLOT(addAirTraficActionTriggered()));

    QMenu *systemMenu = menuBarInstance->addMenu("S&ystem");
    exitAction = new QAction(tr("&Exit"), this);
    systemMenu->addAction(exitAction);
    connect(exitAction, SIGNAL(triggered()), this, SLOT(exitActionTriggered()));

}

/* SLOTs methods */

void AtsMainWindow::exitActionTriggered() {
    exitApplication();
}

void AtsMainWindow::addAirTraficActionTriggered() {
    showAddAirtrafficDialog();
}

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

} /* namespace display */
} /* namespace ats */
