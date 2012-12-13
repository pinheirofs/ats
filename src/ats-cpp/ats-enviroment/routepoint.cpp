#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/velocity.hpp>

#include "routepoint.h"

namespace ats {
namespace enviroment {

using boost::units::si::meters;
using boost::units::si::meters_per_second;

const UnitVelocity RoutePoint::DEFALUT_SPEED(0.0 * meters_per_second);
const UnitLength RoutePoint::DEFALUT_HEIGTH(0.0 * meters);
const UnitLength RoutePoint::DEFALUT_LATITUDE(0.0 * meters);
const UnitLength RoutePoint::DEFALUT_LONGITUDE(0.0 * meters);

RoutePoint::RoutePoint() :
		speed(DEFALUT_SPEED), heigth(DEFALUT_HEIGTH), latitude(DEFALUT_LATITUDE), longitude(
				DEFALUT_LONGITUDE) {
}

RoutePoint::~RoutePoint() {
	// sem implementacao
}

UnitVelocity RoutePoint::getSpeed() {
	return speed;
}

void RoutePoint::setSpeed(UnitVelocity speed) {
	this->speed = speed;
}

UnitLength RoutePoint::getHeigth() {
	return heigth;
}

void RoutePoint::setHeigth(UnitLength heigth) {
	this->heigth = heigth;
}

UnitLength RoutePoint::getLatitude() {
	return latitude;
}

void RoutePoint::setLatitude(UnitLength latitude) {
	this->latitude = latitude;
}

UnitLength RoutePoint::getLongitude() {
	return longitude;
}

void RoutePoint::setLongitude(UnitLength longitude) {
	this->longitude = longitude;
}

} /* namespace enviroment */
} /* namespace ats */
