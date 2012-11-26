#ifndef AIRCRAFTFACTORY_H_
#define AIRCRAFTFACTORY_H_

#include "aircraft.h"
#include "traffic.h"

namespace ats {
namespace enviroment {

/*
 *
 */
class AircraftFactory {
    public:
        AircraftFactory();
        virtual ~AircraftFactory();

        Aircraft create(const Traffic traffic);
};

} /* namespace enviroment */
} /* namespace ats */
#endif /* AIRCRAFTFACTORY_H_ */
