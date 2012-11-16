#include "guifactory.h"
#include "applicationcontroller.h"
#include "atsmainwindow.h"
#include "airtrafficcontroller.h"
#include "airtrafficdialog.h"

using namespace ats::display;

GuiFactory *GuiFactory::INSTANCE = 0;

GuiFactory::GuiFactory() : mainWindow(0) {
}

GuiFactory::~GuiFactory() {
    // sem implemetacao
}

GuiFactory *GuiFactory::getInstance() {
    if (!GuiFactory::INSTANCE) {
        GuiFactory::INSTANCE = new GuiFactory();
    }

    return GuiFactory::INSTANCE;
}

void GuiFactory::showAtsMainWindow() {
    ApplicationController *controller = new ApplicationController(&application);

    mainWindow = new AtsMainWindow(controller);

    connect(mainWindow, SIGNAL(exitApplication()), mainWindow, SLOT(close()));
    connect(mainWindow, SIGNAL(showAddAirtrafficDialog()), this, SLOT(showAirTrafficManagementWindow()));

    mainWindow->show();
}

void GuiFactory::showAirTrafficManagementWindow() {
    AirTrafficController *controller = new AirTrafficController(&application);

    AirTrafficDialog *dialog = new AirTrafficDialog(mainWindow);

    connect(dialog, SIGNAL(addRoutePoint(int)), controller, SLOT(addRoutePoint(int)));
    connect(dialog, SIGNAL(removeRoutePoint(int)), controller, SLOT(removeRoutePoint(int)));
    connect(dialog, SIGNAL(setTrafficName(const QString &)), controller, SLOT(setTrafficName(const QString &)));
    connect(dialog, SIGNAL(setTrafficLatitude(const int, const double)), controller, SLOT(setTrafficLatitude(const int, const double)));
    connect(dialog, SIGNAL(setTrafficLongitude(const int, const double)), controller, SLOT(setTrafficLongitude(const int, const double)));
    connect(dialog, SIGNAL(setTrafficHeight(const int, const double)), controller, SLOT(setTrafficHeight(const int, const double)));
    connect(dialog, SIGNAL(setTrafficSpeed(const int, const double)), controller, SLOT(setTrafficSpeed(const int, const double)));
    connect(dialog, SIGNAL(isValidTraffic()), controller, SLOT(isValidTraffic()));
    connect(dialog, SIGNAL(saveTraffic()), controller, SLOT(saveTraffic()));

    dialog->show();
}
