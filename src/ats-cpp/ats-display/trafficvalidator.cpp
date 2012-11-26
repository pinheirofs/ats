#include <string>
#include <vector>

#include "routepoint.h"
#include "trafficvalidator.h"

using std::vector;

namespace ats {
namespace enviroment {

const double TrafficValidator::HEIGTH_MAX_FT = 100000.0;
const double TrafficValidator::HEIGTH_MIN_FT = 0.0;
const double TrafficValidator::LATITUDE_MAX_DEGREES = 89.9;
const double TrafficValidator::LATITUDE_MIN_DEGREES = -89.9;
const double TrafficValidator::LONGITUDE_MAX_DEGREES = 189.9;
const double TrafficValidator::LONGITUDE_MIN_DEGREES = -189.9;
const double TrafficValidator::SPEED_MAX_KT = 5000.0;
const double TrafficValidator::SPEED_MIN_KT = 0.0;

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
            double heigth_ft = traffic.getRoutePointHeight_ft(i);
            if (heigth_ft == RoutePoint::DEFALUT_HEIGTH_FT) {
                return false;
            } else if (heigth_ft < HEIGTH_MIN_FT || heigth_ft > HEIGTH_MAX_FT) {
                return false;
            }

            double latitude_degrees = traffic.getRoutePointLatitude_degrees(i);
            if (latitude_degrees == RoutePoint::DEFALUT_LATITUDE_DEGREES) {
                return false;
            } else if (latitude_degrees < LATITUDE_MIN_DEGREES || latitude_degrees > LATITUDE_MAX_DEGREES) {
                return false;
            }

            double longitude_degrees = traffic.getRoutePointLongitude_degrees(i);
            if (longitude_degrees == RoutePoint::DEFALUT_LONGITUDE_DEGREES) {
                return false;
            } else if (longitude_degrees < LONGITUDE_MIN_DEGREES || longitude_degrees > LONGITUDE_MAX_DEGREES) {
                return false;
            }

            double speed_kt = traffic.getRoutePointSpeed_kt(i);
            if (speed_kt == RoutePoint::DEFALUT_SPEED_KT) {
                return false;
            } else if (speed_kt < SPEED_MIN_KT || speed_kt > SPEED_MAX_KT) {
                return false;
            }
        }

        return true;
}

} /* namespace enviroment */
} /* namespace ats */
