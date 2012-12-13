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

        for (int i = 0; i < countRoutePoints; i++) {
            UnitLength heigth = traffic.getRoutePointHeight(i);
            if (heigth == RoutePoint::DEFALUT_HEIGTH) {
                return false;
            } else if (heigth < HEIGTH_MIN || heigth > HEIGTH_MAX) {
                return false;
            }

            UnitLength latitude = traffic.getRoutePointLatitude(i);
            if (latitude == RoutePoint::DEFALUT_LATITUDE) {
                return false;
            } else if (latitude < LATITUDE_MIN || latitude > LATITUDE_MAX) {
                return false;
            }

            UnitLength longitude_degrees = traffic.getRoutePointLongitude(i);
            if (longitude_degrees == RoutePoint::DEFALUT_LONGITUDE) {
                return false;
            } else if (longitude_degrees < LONGITUDE_MIN || longitude_degrees > LONGITUDE_MAX) {
                return false;
            }

            UnitVelocity speed = traffic.getRoutePointSpeed(i);
            if (speed == RoutePoint::DEFALUT_SPEED) {
                return false;
            } else if (speed < SPEED_MIN || speed > SPEED_MAX) {
                return false;
            }
        }

        return true;
}

} /* namespace enviroment */
} /* namespace ats */
