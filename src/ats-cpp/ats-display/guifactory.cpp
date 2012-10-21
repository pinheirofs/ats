#include "guifactory.hpp"
#include "applicationcontroller.hpp"
#include "atsmainwindow.hpp"

using namespace ats::display;

GuiFactory *GuiFactory::INSTANCE = 0;

GuiFactory::GuiFactory() {
    // TODO Auto-generated constructor stub

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

void GuiFactory::showAtsMainWindow(Application *application) {
    ApplicationController *controller = new ApplicationController(application);

    AtsMainWindow *window = new AtsMainWindow(controller);

    connect(window->getExitAction(), SIGNAL(triggered()), window, SLOT(close()));

    window->show();
}
