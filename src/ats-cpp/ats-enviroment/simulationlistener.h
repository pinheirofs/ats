#ifndef SIMULATIONLISTENER_H_
#define SIMULATIONLISTENER_H_

#include <string>

#include "coordinate.h"

namespace ats {
namespace enviroment {

/*
 *
 */
class SimulationListener {
    public:
        SimulationListener();
        virtual ~SimulationListener();

        virtual void notify(const std::string name, const Coordinate coordinate) const;
};

} /* namespace enviroment */
} /* namespace ats */
#endif /* SIMULATIONLISTENER_H_ */
