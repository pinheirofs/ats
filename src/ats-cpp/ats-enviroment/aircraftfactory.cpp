#include "aircraftfactory.h"
#include "converter.h"
#include "streachcalculator.h"
#include "typedefs.h"

namespace ats {
namespace enviroment {

AircraftFactory::AircraftFactory() {
}

AircraftFactory::~AircraftFactory() {
}

Aircraft AircraftFactory::create(const Traffic traffic) {
    Aircraft aircraft;

    aircraft.setName(traffic.getName());

    StreachCalculator streachCalculator;
    streachCalculator.setInitHeight(traffic.getRoutePointHeight(0));
    streachCalculator.setInitLatitude(traffic.getRoutePointLatitude(0));
    streachCalculator.setInitLongitude(traffic.getRoutePointLongitude(0));
    streachCalculator.setInitSpeed(traffic.getRoutePointSpeed(0));

    Converter converter;
    UnitTime simulationTime = 0;
    for (int i = 1; i < traffic.countRoutePoints(); i++) {
        streachCalculator.setEndHeight(traffic.getRoutePointHeight(i));
        streachCalculator.setEndLatitude(traffic.getRoutePointLatitude(i));
        streachCalculator.setEndLongitude(traffic.getRoutePointLongitude(i));
        streachCalculator.setEndSpeed(traffic.getRoutePointSpeed(i));

        simulationTime += streachCalculator.calculateTimeInterval();

        Stretch stretch;
        stretch.setLimitTime(simulationTime);
        stretch.setHeightChangeRate(streachCalculator.calculateHeightChangeRate());
        stretch.setSpeedChangeRate(streachCalculator.calculateSpeedChangeRate());
        stretch.setHeading(streachCalculator.calculateHeading());
        stretch.setInitSpeed(streachCalculator.getInitSpeed());
        stretch.setInitHeight(streachCalculator.getInitHeight());
        stretch.setInitLatitude(streachCalculator.getInitLatitude());
        stretch.setInitLongitude(streachCalculator.getInitLongitude());

        streachCalculator.advance();
    }

    return aircraft;
}

} /* namespace enviroment */
} /* namespace ats */
