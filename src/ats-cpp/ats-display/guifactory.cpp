#include "guifactory.hpp"
#include "applicationcontroller.hpp"
#include "atsmainwindow.hpp"
#include "airtrafficmanagementcontroller.hpp"
#include "airtrafficmanagementdialog.hpp"

using namespace ats::display;

GuiFactory *GuiFactory::INSTANCE = 0;

GuiFactory::GuiFactory() : mainWindow(0) {
}

GuiFactory::~GuiFactory() {
    // TODO Auto-generated destructor stub
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
    AirTrafficManagementController *controller = new AirTrafficManagementController(&application);

    AirTrafficManagementDialog *dialog = new AirTrafficManagementDialog(mainWindow, controller);

    dialog->show();
}
