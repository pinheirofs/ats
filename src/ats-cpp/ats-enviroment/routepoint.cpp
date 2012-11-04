#include "routepoint.h"

namespace ats {
namespace enviroment {

RoutePoint::RoutePoint()
        : id(0), speed_mn(0.0), heigth_ft(0.0), latitude_degrees(0.0), longitude_degrees(0.0) {
}

RoutePoint::~RoutePoint() {
    // sem implementacao
}

int RoutePoint::getId() {
    return id;
}

void RoutePoint::setId(int id) {
    this->id = id;
}

double RoutePoint::getSpeed_mn() {
    return speed_mn;
}

void RoutePoint::setSpeed_mn(double speed_mn) {
    this->speed_mn = speed_mn;
}

double RoutePoint::getHeigth_ft() {
    return heigth_ft;
}

void RoutePoint::setHeigth_ft(double heigth_ft) {
    this->heigth_ft = heigth_ft;
}

double RoutePoint::getLatitude_degrees() {
    return latitude_degrees;
}

void RoutePoint::setLatitude_degrees(double latitude_degrees) {
    this->latitude_degrees = latitude_degrees;
}

double RoutePoint::getLongitude_degrees() {
    return longitude_degrees;
}

void RoutePoint::setLongitude_degrees(double longitude_degrees) {
    this->longitude_degrees = longitude_degrees;
}

bool RoutePoint::operator ==(const RoutePoint& other) {
    return this->id == other.id;
}

} /* namespace enviroment */
} /* namespace ats */
