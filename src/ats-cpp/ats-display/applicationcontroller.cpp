#include "applicationcontroller.h"

namespace ats {
namespace display {

ApplicationController::ApplicationController(Application *application) : application(application) {
}

ApplicationController::~ApplicationController() {
    // sem implemetacao
}

bool ApplicationController::isRunningSimulation() {
    return true;
}

} /* namespace display */
} /* namespace ats */
