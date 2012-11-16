#include "routepoint.h"

namespace ats {
namespace enviroment {

const double RoutePoint::DEFALUT_SPEED_KT = -1.0;
const double RoutePoint::DEFALUT_HEIGTH_FT = -1.0;
const double RoutePoint::DEFALUT_LATITUDE_DEGREES = -100.0;
const double RoutePoint::DEFALUT_LONGITUDE_DEGREES = -200.0;

RoutePoint::RoutePoint()
        : speed_kt(DEFALUT_SPEED_KT), heigth_ft(DEFALUT_HEIGTH_FT), latitude_degrees(DEFALUT_LATITUDE_DEGREES), longitude_degrees(
                DEFALUT_LONGITUDE_DEGREES) {
}

RoutePoint::~RoutePoint() {
    // sem implementacao
}

double RoutePoint::getSpeed_kt() {
    return speed_kt;
}

void RoutePoint::setSpeed_kt(double speed_kt) {
    this->speed_kt = speed_kt;
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

} /* namespace enviroment */
} /* namespace ats */
