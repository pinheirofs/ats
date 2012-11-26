#include <vector>

#include "aircraft.h"
#include "aircraftfactory.h"
#include "applicationcontroller.h"
#include "traffic.h"

using std::vector;

using ats::enviroment::Aircraft;
using ats::enviroment::AircraftFactory;
using ats::enviroment::Traffic;

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

void ApplicationController::prepareSimulation() {
    simulation.clearAircrafts();

    AircraftFactory aircraftFactory;

    vector<Traffic> traffics = application->getAllTraffics();
    vector<Traffic>::iterator iterator = traffics.begin();
    while (iterator != traffics.end()) {
        Traffic traffic = *iterator;

        Aircraft aircraft = aircraftFactory.create(traffic);
        simulation.addAircraft(aircraft);
    }
}

void ApplicationController::startSimulation() {
    simulation.start();
}

} /* namespace display */
} /* namespace ats */
