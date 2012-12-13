#include <sys/timeb.h>
#include <vector>

#include "coordinate.h"
#include "simulation.h"

using std::vector;
using boost::units::si::seconds;

namespace ats {
namespace enviroment {

Simulation::Simulation()
        : sleepTime(0), startedTime(0) {
}

Simulation::~Simulation() {
}

void Simulation::addAircraft(Aircraft &aircraft) {
    aircrafts.push_back(aircraft);
}

void Simulation::setSleepTime(UnitTime sleepTime) {
    this->sleepTime = sleepTime;
}

void Simulation::addSimulationListener(SimulationListener simulationListener) {
    simulationListeners.push_back(simulationListener);
}

void Simulation::clearAircrafts() {
    aircrafts.clear();
}

void Simulation::evolve(Aircraft& aircraft, UnitTime time) {
    Coordinate coordiante = aircraft.evolve(time);

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

        UnitTime deltaTime = getTime() - startedTime;
        if (!aircraft.isFlying(deltaTime)) {
            aircrafts.erase(iterator);
        } else {
            evolve(aircraft, deltaTime);
        }

        iterator++;
    }
}

void Simulation::start() {
    startedTime = getTime();

    while (!aircrafts.empty()) {
        evolveAllAircarft();
    }
}

UnitTime Simulation::getTime() {
    struct timeb instant;
    ftime(&instant);
    
    double instantSeconds = instant.time;
    double instantMiliseconds = instant.millitm;
    double time = instantSeconds + (instantMiliseconds / 1000.0);
    return UnitTime(time * seconds);
}

} /* namespace enviroment */
} /* namespace ats */
