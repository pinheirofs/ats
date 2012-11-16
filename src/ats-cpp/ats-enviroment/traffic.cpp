#include "traffic.h"

using std::string;

namespace ats {
namespace enviroment {

Traffic::Traffic() {
    // sem implementacao
}

Traffic::~Traffic() {
    // sem implementacao
}

string Traffic::getName() const {
    return name;
}

void Traffic::setName(const string& name) {
    this->name = name;
}

void Traffic::addRoutePointAt(int index) {
    RoutePoint routePoint;
    routePoints.insert(routePoints.begin() + index, routePoint);
}

void Traffic::removeRoutePointAt(int index) {
    routePoints.erase(routePoints.begin() + index);
}

void Traffic::setRoutePointLatitudeAt(const int index, double latitude) {
    RoutePoint point = routePoints[index];
    point.setLatitude_degrees(latitude);
}

void Traffic::setRoutePointLongitudeAt(const int index, double longitude) {
    RoutePoint point = routePoints[index];
    point.setLongitude_degrees(longitude);
}

void Traffic::setRoutePointSpeedAt(const int index, double speed) {
    RoutePoint point = routePoints[index];
    point.setSpeed_mn(speed);
}

void Traffic::setRoutePointHeightAt(const int index, double height) {
    RoutePoint point = routePoints[index];
    point.setHeigth_ft(height);
}

} /* namespace enviroment */
} /* namespace ats */
