#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <vector>

#include "aircraft.h"
#include "simulationlistener.h"
#include "typedefs.h"

namespace ats {
namespace enviroment {

class Simulation {
    public:
        Simulation();
        virtual ~Simulation();

        void clearAircrafts();
        void addAircraft(Aircraft &aircraft);
        int quantityAircrafts();
        void setSleepTime(UnitTime sleepTime);
        UnitTime getSleepTime();
        void addSimulationListener(SimulationListener simulationListener);
        int quantitySimulationListeners();
        void start();

    private:
        std::vector<Aircraft> aircrafts;
        std::vector<SimulationListener> simulationListeners;
        UnitTime sleepTime;
        UnitTime startedTime;

        void evolveAllAircarft();
        void evolve(Aircraft& aircraft, UnitTime time);

        static UnitTime getTime();
};

} /* namespace enviroment */
} /* namespace ats */
#endif /* SIMULATION_H_ */
