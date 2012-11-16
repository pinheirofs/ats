#include <qstring.h>
#include <vector>

#include "airtrafficmanagementcontroller.h"
#include "routepoint.h"
#include "traffic.h"

using std::string;
using std::vector;
using ats::enviroment::Traffic;

namespace ats {
namespace display {

AirTrafficManagementController::AirTrafficManagementController(Application *application)
        : application(application) {
}

AirTrafficManagementController::~AirTrafficManagementController() {
    // sem implementacao
}

void AirTrafficManagementController::setTrafficName(const QString &name) {
    traffic.setName(name.toUtf8().constData());
}
void AirTrafficManagementController::setTrafficLatitude(const int indexRoutePoint, const double latitude) {
    traffic.setRoutePointLatitudeAt(indexRoutePoint, latitude);
}

void AirTrafficManagementController::setTrafficLongitude(const int indexRoutePoint, const double longitude) {
    traffic.setRoutePointLongitudeAt(indexRoutePoint, longitude);
}

void AirTrafficManagementController::setTrafficHeight(const int indexRoutePoint, const double height) {
    traffic.setRoutePointHeightAt(indexRoutePoint, height);
}

void AirTrafficManagementController::setTrafficSpeed(const int indexRoutePoint, const double speed) {
    traffic.setRoutePointSpeedAt(indexRoutePoint, speed);
}

void AirTrafficManagementController::saveTraffic() {
    application->addTraffic(traffic);
}

void AirTrafficManagementController::addRoutePoint(int index) {
    traffic.addRoutePointAt(index);
}

void AirTrafficManagementController::removeRoutePoint(int index) {
    traffic.removeRoutePointAt(index);
}

} /* namespace display */
} /* namespace ats */
