#include <string>
#include <vector>

#include "routepoint.h"
#include "trafficvalidator.h"

using std::vector;
using boost::units::si::meters;
using boost::units::si::meters_per_second;

namespace ats {
namespace enviroment {

const UnitLength TrafficValidator::HEIGTH_MAX(3096.0 * meters);
const UnitLength TrafficValidator::HEIGTH_MIN(0.0 * meters);
const UnitLength TrafficValidator::LATITUDE_MAX(110000.0 * meters);
const UnitLength TrafficValidator::LATITUDE_MIN(-110000.0 * meters);
const UnitLength TrafficValidator::LONGITUDE_MAX(20001600.0 * meters);
const UnitLength TrafficValidator::LONGITUDE_MIN(-20001600.0 * meters);
const UnitVelocity TrafficValidator::SPEED_MAX(2572.22222 * meters_per_second);
const UnitVelocity TrafficValidator::SPEED_MIN(0.0 * meters_per_second);

TrafficValidator::TrafficValidator() {
}

TrafficValidator::~TrafficValidator() {
}

void TrafficValidator::setTraffic(const Traffic traffic) {
    this->traffic = traffic;
}

bool TrafficValidator::isValid() const {
    if (traffic.getName().empty()) {
            return false;
        }

        int countRoutePoints = traffic.countRoutePoints();
        if (countRoutePoints < 2) {
            return false;
        }

        return true;
}

} /* namespace enviroment */
} /* namespace ats */
