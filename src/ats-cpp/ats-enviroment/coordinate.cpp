#define _USE_MATH_DEFINES

#include <cmath>

#include "converter.h"
#include "coordinate.h"

namespace ats {
namespace enviroment {


Coordinate::Coordinate()
        : latitude_rad(0.0), longitude_rad(0.0), height_ft(0.0) {
}

Coordinate::Coordinate(double latitude_deg, double longitude_deg, double height_ft) : height_ft(height_ft) {
    Converter converter;
    latitude_rad = converter.convertDegreesToRadian(latitude_deg);
    longitude_rad = converter.convertDegreesToRadian(longitude_deg);
}

Coordinate::~Coordinate() {
}

double Coordinate::getLatitude_deg() const {
    Converter converter;
    return converter.convertRadianToDegrees(latitude_rad);
}

double Coordinate::getLatitude_rad() const {
    return latitude_rad;
}

double Coordinate::getLongitude_deg() const {
    Converter converter;
    return converter.convertRadianToDegrees(longitude_rad);
}

double Coordinate::getLongitude_rad() const {
    return longitude_rad;
}

double Coordinate::getHeight_ft() const {
    return height_ft;
}

} /* namespace enviroment */
} /* namespace ats */
