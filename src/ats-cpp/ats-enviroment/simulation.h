#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <map>
#include <vector>

#include "aircraft.h"
#include "simulationlistener.h"

namespace ats {
namespace enviroment {

/*
 *
 */
class Simulation {
    public:
        Simulation();
        virtual ~Simulation();

        void addAircraft(Aircraft &aircraft);
        void setSleepTime_msec(long sleepTime);
        void addSimulationListener(SimulationListener simulationListener);
        void start();

    private:
        std::vector<Aircraft> aircrafts;
        std::vector<SimulationListener> simulationListeners;
        long sleepTime;
};

} /* namespace enviroment */
} /* namespace ats */
#endif /* SIMULATION_H_ */
