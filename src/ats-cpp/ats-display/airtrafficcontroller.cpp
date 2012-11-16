#include <qstring.h>
#include <vector>

#include "airtrafficcontroller.h"
#include "routepoint.h"
#include "traffic.h"
#include "trafficvalidator.h"

using std::string;
using std::vector;

using ats::enviroment::RoutePoint;
using ats::enviroment::Traffic;
using ats::enviroment::TrafficValidator;

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
void AirTrafficController::setTrafficLatitude(const int indexRoutePoint, const double latitude) {
    traffic.setRoutePointLatitudeAt(indexRoutePoint, latitude);
}

void AirTrafficController::setTrafficLongitude(const int indexRoutePoint, const double longitude) {
    traffic.setRoutePointLongitudeAt(indexRoutePoint, longitude);
}

void AirTrafficController::setTrafficHeight(const int indexRoutePoint, const double height) {
    traffic.setRoutePointHeightAt(indexRoutePoint, height);
}

void AirTrafficController::setTrafficSpeed(const int indexRoutePoint, const double speed) {
    traffic.setRoutePointSpeedAt(indexRoutePoint, speed);
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
