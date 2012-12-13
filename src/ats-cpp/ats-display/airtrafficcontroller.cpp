#include <qstring.h>
#include <vector>

#include <boost/units/quantity.hpp>
#include <boost/units/systems/si/length.hpp>

#include "airtrafficcontroller.h"
#include "routepoint.h"
#include "traffic.h"
#include "trafficvalidator.h"

using std::string;
using std::vector;

using ats::enviroment::RoutePoint;
using ats::enviroment::Traffic;
using ats::enviroment::TrafficValidator;

using boost::units::quantity;
using boost::units::si::length;
using boost::units::si::meters;
using boost::units::si::meters_per_second;
using boost::units::si::velocity;

namespace ats {
namespace display {

AirTrafficController::AirTrafficController(Application *application)
        : application(application) {
}

AirTrafficController::~AirTrafficController() {
    // sem implementacao
}

void AirTrafficController::setTrafficName(const QString &name) {
    traffic.setName(name.toUtf8().constData());
}
void AirTrafficController::setTrafficLatitude(const int indexRoutePoint, const double latitude_deg) {
	quantity<length> latitude(latitude_deg * 110000.0 * meters);
    traffic.setRoutePointLatitude(indexRoutePoint, latitude);
}

void AirTrafficController::setTrafficLongitude(const int indexRoutePoint, const double longitude_deg) {
	quantity<length> longitude(longitude_deg * 111120.0 * meters);
    traffic.setRoutePointLongitude(indexRoutePoint, longitude);
}

void AirTrafficController::setTrafficHeight(const int indexRoutePoint, const double height_ft) {
	quantity<length> height(height_ft * 0.3048 * meters);
    traffic.setRoutePointHeight(indexRoutePoint, height);
}

void AirTrafficController::setTrafficSpeed(const int indexRoutePoint, const double speed_kt) {
	quantity<velocity> speed(speed_kt * 0.514444444 * meters_per_second);
    traffic.setRoutePointSpeed(indexRoutePoint, speed);
}

bool AirTrafficController::isValidTraffic() {
    TrafficValidator trafficValidator;
    trafficValidator.setTraffic(traffic);

    return trafficValidator.isValid();
}

void AirTrafficController::saveTraffic() {
    application->addTraffic(traffic);
}

void AirTrafficController::addRoutePoint(int index) {
    traffic.addRoutePointAt(index);
}

void AirTrafficController::removeRoutePoint(int index) {
    traffic.removeRoutePointAt(index);
}

} /* namespace display */
} /* namespace ats */
