#include "guifactory.h"
#include "applicationcontroller.h"
#include "atsmainwindow.h"
#include "airtrafficmanagementcontroller.h"
#include "airtrafficmanagementdialog.h"

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

    connect(mainWindow->getExitAction(), SIGNAL(triggered()), mainWindow, SLOT(close()));
    connect(mainWindow->getAirTrafficManagementAction(), SIGNAL(triggered()), this, SLOT(showAirTrafficManagementWindow()));

    mainWindow->show();
}

void GuiFactory::showAirTrafficManagementWindow() {
    AirTrafficManagementController *controller = new AirTrafficManagementController();

    AirTrafficManagementDialog *dialog = new AirTrafficManagementDialog(mainWindow);

    connect(dialog, SIGNAL(setTrafficName(const QString &)), controller, SLOT(setTrafficName(const QString &)));
    connect(dialog, SIGNAL(setTrafficLatitude(const int, const double)), controller, SLOT(setTrafficLatitude(const int, const double)));
    connect(dialog, SIGNAL(setTrafficLongitude(const int, const double)), controller, SLOT(setTrafficLongitude(const int, const double)));
    connect(dialog, SIGNAL(setTrafficHeight(const int, const double)), controller, SLOT(setTrafficHeight(const int, const double)));
    connect(dialog, SIGNAL(setTrafficSpeed(const int, const double)), controller, SLOT(setTrafficSpeed(const int, const double)));
    connect(dialog, SIGNAL(saveTraffic()), controller, SLOT(saveTraffic()));
    connect(dialog, SIGNAL(addRoutePoint(int)), controller, SLOT(addRoutePoint(int)));
    connect(dialog, SIGNAL(removeRoutePoint(int)), controller, SLOT(removeRoutePoint(int)));

    dialog->show();
}
