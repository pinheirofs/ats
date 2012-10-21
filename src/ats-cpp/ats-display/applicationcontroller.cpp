#include "applicationcontroller.hpp"

namespace ats {
namespace display {

ApplicationController::ApplicationController(Application *application) : application(application) {
    // TODO Auto-generated constructor stub

}

ApplicationController::~ApplicationController() {
    // TODO Auto-generated destructor stub
}

bool ApplicationController::isRunningSimulation() {
    return true;
}

} /* namespace display */
} /* namespace ats */
