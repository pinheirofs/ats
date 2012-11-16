#include "simulation.h"

namespace ats {
namespace enviroment {

Simulation::Simulation() : sleepTime(0) {
}

Simulation::~Simulation() {
}

void Simulation::addAircraft(Aircraft &aircraft) {
    aircrafts.push_back(aircraft);
}

void Simulation::setSleepTime_msec(long sleepTime) {
    this->sleepTime = sleepTime;
}

void Simulation::addSimulationListener(SimulationListener simulationListener) {
    simulationListeners.push_back(simulationListener);
}

void Simulation::start() {

}

} /* namespace enviroment */
} /* namespace ats */
