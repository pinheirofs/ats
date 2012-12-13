#define _USE_MATH_DEFINES

#include <cmath>

#include "converter.h"
#include "coordinate.h"

using boost::units::si::meters;

namespace ats {
namespace enviroment {

Coordinate::Coordinate() :
		latitude(0.0 * meters), longitude(0.0 * meters), height(0.0 * meters) {
}

Coordinate::~Coordinate() {
}

UnitLength Coordinate::getLatitude() const {
	return latitude;
}

UnitLength Coordinate::getLongitude() const {
	return longitude;
}

UnitLength Coordinate::getHeight() const {
	return height;
}

} /* namespace enviroment */
} /* namespace ats */
