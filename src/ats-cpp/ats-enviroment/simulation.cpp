#include <sys/timeb.h>
#include <vector>

#include "coordinate.h"
#include "simulation.h"

using std::vector;

namespace ats {
namespace enviroment {

Simulation::Simulation()
        : sleepTime(0), startedTime_ms(0) {
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

void Simulation::clearAircrafts() {
    aircrafts.clear();
}

void Simulation::evolve(Aircraft& aircraft, long time_ms) {
    Coordinate coordiante = aircraft.evolve(time_ms);

    std::vector<SimulationListener>::iterator iterator = simulationListeners.begin();
    while (iterator != simulationListeners.end()) {
        SimulationListener simulationListener = *iterator;
        simulationListener.notify(aircraft.getName(), coordiante);
    }
}

void Simulation::evolveAllAircarft() {
    vector<Aircraft>::iterator iterator = aircrafts.begin();
    while (iterator != aircrafts.end()) {
        Aircraft aircraft = *iterator;

        long deltaTime_ms = getTime_ms() - startedTime_ms;
        if (!aircraft.isFlying(deltaTime_ms)) {
            aircrafts.erase(iterator);
        } else {
            evolve(aircraft, deltaTime_ms);
        }

        iterator++;
    }
}

void Simulation::start() {
    startedTime_ms = getTime_ms();

    while (!aircrafts.empty()) {
        evolveAllAircarft();
    }
}

long Simulation::getTime_ms() {
    struct timeb time;
    ftime(&time);
    return time.time * 1000 + time.millitm;
}

} /* namespace enviroment */
} /* namespace ats */
