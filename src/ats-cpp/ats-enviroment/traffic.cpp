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

void Traffic::setRoutePointLatitude_degrees(const int index, double latitude_degrees) {
    RoutePoint point = routePoints[index];
    point.setLatitude_degrees(latitude_degrees);
    routePoints[index] = point;
}

double Traffic::getRoutePointLatitude_degrees(const int index) const {
    RoutePoint point = routePoints[index];
    return point.getLatitude_degrees();
}

void Traffic::setRoutePointLongitude_degrees(const int index, double longitude_degrees) {
    RoutePoint point = routePoints[index];
    point.setLongitude_degrees(longitude_degrees);
    routePoints[index] = point;
}

double Traffic::getRoutePointLongitude_degrees(const int index) const {
    RoutePoint point = routePoints[index];
    return point.getLongitude_degrees();
}

void Traffic::setRoutePointSpeed_kt(const int index, double speed_kt) {
    RoutePoint point = routePoints[index];
    point.setSpeed_kt(speed_kt);
    routePoints[index] = point;
}

double Traffic::getRoutePointSpeed_kt(const int index) const {
    RoutePoint point = routePoints[index];
    return point.getSpeed_kt();
}

void Traffic::setRoutePointHeight_ft(const int index, double height_ft) {
    RoutePoint point = routePoints[index];
    point.setHeigth_ft(height_ft);
    routePoints[index] = point;
}

double Traffic::getRoutePointHeight_ft(const int index) const {
    RoutePoint point = routePoints[index];
    return point.getHeigth_ft();
}

int Traffic::countRoutePoints() const {
    return routePoints.size();
}

} /* namespace enviroment */
} /* namespace ats */
