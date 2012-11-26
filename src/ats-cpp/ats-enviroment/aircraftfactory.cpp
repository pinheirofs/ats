#include "aircraftfactory.h"
#include "converter.h"
#include "streachcalculator.h"

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
    streachCalculator.setInitHeight_ft(traffic.getRoutePointHeight_ft(0));
    streachCalculator.setInitLatitude_degrees(traffic.getRoutePointLatitude_degrees(0));
    streachCalculator.setInitLongitude_degrees(traffic.getRoutePointLongitude_degrees(0));
    streachCalculator.setInitSpeed_kt(traffic.getRoutePointSpeed_kt(0));

    Converter converter;
    long simulationTime_ms = 0;
    for (int i = 1; i < traffic.countRoutePoints(); i++) {
        streachCalculator.setEndHeight_ft(traffic.getRoutePointHeight_ft(i));
        streachCalculator.setEndLatitude_degrees(traffic.getRoutePointLatitude_degrees(i));
        streachCalculator.setEndLongitude_degrees(traffic.getRoutePointLongitude_degrees(i));
        streachCalculator.setEndSpeed_kt(traffic.getRoutePointSpeed_kt(i));

        simulationTime_ms += streachCalculator.calculateTimeInterval_ms();

        Stretch stretch;
        stretch.setLimitTime_ms(simulationTime_ms);
        stretch.setHeightChangeRate_ft_ms(streachCalculator.calculateHeightChangeRate_ft_ms());
        stretch.setSpeedChangeRate_kt_ms2(streachCalculator.calculateSpeedChangeRate_kt_ms2());
        stretch.setHeading_deg(streachCalculator.calculateHeading_degrees());

        streachCalculator.advance();
    }

    return aircraft;
}

} /* namespace enviroment */
} /* namespace ats */
