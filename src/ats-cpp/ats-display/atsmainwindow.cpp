#include <qmessagebox.h>
#include <qmenubar.h>

#include "atsmainwindow.h"

namespace ats {
namespace display {

AtsMainWindow::AtsMainWindow() {
    config();
    createMenus();
}

AtsMainWindow::~AtsMainWindow() {
}

void AtsMainWindow::config() {
    setWindowTitle(tr("ATS - Air Traffic Simulation"));
    setMinimumSize(800, 600);
}


void AtsMainWindow::createMenus() {
    createAirTrafficMenu();
    createSimulationMenu();
    createSystemMenu();
}

void AtsMainWindow::createSystemMenu() {
    QMenuBar *menuBarInstance = menuBar();
    QMenu* systemMenu = menuBarInstance->addMenu("S&ystem");

    exitAction = new QAction(tr("&Exit"), this);
    systemMenu->addAction(exitAction);
    connect(exitAction, SIGNAL(triggered()), this, SLOT(exitActionTriggered()));
}

void AtsMainWindow::createSimulationMenu() {
    QMenuBar* menuBarInstance = menuBar();
    QMenu* simulationMenu = menuBarInstance->addMenu("&Simulation");

    prepareSimulationAction = new QAction(tr("&Prepare"), this);
    simulationMenu->addAction(prepareSimulationAction);
    connect(prepareSimulationAction, SIGNAL(triggered()), this, SLOT(prepareSimulationActionTriggered()));

    startSimulationAction = new QAction(tr("&Start"), this);
    simulationMenu->addAction(startSimulationAction);
    connect(startSimulationAction, SIGNAL(triggered()), this, SLOT(startSimulationActionTriggered()));
}

void AtsMainWindow::createAirTrafficMenu() {
    QMenuBar *menuBarInstance = menuBar();
    QMenu* simulationMenu = menuBarInstance->addMenu("&Air Traffic");

    addAirTraficAction = new QAction(tr("&Add"), this);
    simulationMenu->addAction(addAirTraficAction);
    connect(addAirTraficAction, SIGNAL(triggered()), this, SLOT(addAirTraficActionTriggered()));
}

/* SLOTs methods */

void AtsMainWindow::prepareSimulationActionTriggered() {
    prepareSimulation();
}

void AtsMainWindow::startSimulationActionTriggered() {
    startSimulation();
}

void AtsMainWindow::exitActionTriggered() {
    exitApplication();
}

void AtsMainWindow::addAirTraficActionTriggered() {
    showAddAirtrafficDialog();
}

void AtsMainWindow::closeEvent(QCloseEvent * event) {
    if (isRunningSimulation()) {
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
