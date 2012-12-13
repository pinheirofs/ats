#include "traffic.h"

using std::string;
using std::vector;

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
    vector<RoutePoint>::iterator iterator =routePoints.begin();
    iterator += index;
    routePoints.erase(iterator);
}

void Traffic::setRoutePointLatitude(const int index, UnitLength latitude) {
    RoutePoint point = routePoints[index];
    point.setLatitude(latitude);
    routePoints[index] = point;
}

UnitLength Traffic::getRoutePointLatitude(const int index) const {
    RoutePoint point = routePoints[index];
    return point.getLatitude();
}

void Traffic::setRoutePointLongitude(const int index, UnitLength longitude) {
    RoutePoint point = routePoints[index];
    point.setLongitude(longitude);
    routePoints[index] = point;
}

UnitLength Traffic::getRoutePointLongitude(const int index) const {
    RoutePoint point = routePoints[index];
    return point.getLongitude();
}

void Traffic::setRoutePointSpeed(const int index, UnitVelocity speed) {
    RoutePoint point = routePoints[index];
    point.setSpeed(speed);
    routePoints[index] = point;
}

UnitVelocity Traffic::getRoutePointSpeed(const int index) const {
    RoutePoint point = routePoints[index];
    return point.getSpeed();
}

void Traffic::setRoutePointHeight(const int index, UnitLength height) {
    RoutePoint point = routePoints[index];
    point.setHeigth(height);
    routePoints[index] = point;
}

UnitLength Traffic::getRoutePointHeight(const int index) const {
    RoutePoint point = routePoints[index];
    return point.getHeigth();
}

int Traffic::countRoutePoints() const {
    return routePoints.size();
}

} /* namespace enviroment */
} /* namespace ats */
