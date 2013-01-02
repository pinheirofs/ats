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
        std::vector<Aircraft> getAllAircrafts();
        void setSleepTime(UnitTime sleepTime);
        void addSimulationListener(SimulationListener simulationListener);
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
