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
    routePoints.erase(routePoints.begin() + index);
}

void Traffic::setRoutePointLatitudeAt(const int index, double latitude) {
    RoutePoint point = routePoints[index];
    point.setLatitude_degrees(latitude);
    routePoints[index] = point;
}

void Traffic::setRoutePointLongitudeAt(const int index, double longitude) {
    RoutePoint point = routePoints[index];
    point.setLongitude_degrees(longitude);
    routePoints[index] = point;
}

void Traffic::setRoutePointSpeedAt(const int index, double speed) {
    RoutePoint point = routePoints[index];
    point.setSpeed_kt(speed);
    routePoints[index] = point;
}

void Traffic::setRoutePointHeightAt(const int index, double height) {
    RoutePoint point = routePoints[index];
    point.setHeigth_ft(height);
    routePoints[index] = point;
}

vector<RoutePoint> Traffic::getRoutePoints() const {
    return routePoints;
}

} /* namespace enviroment */
} /* namespace ats */
