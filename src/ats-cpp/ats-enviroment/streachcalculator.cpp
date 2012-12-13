#include <cmath>
#include <boost/units/pow.hpp>

#include "streachcalculator.h"
#include "converter.h"

using boost::units::pow;
using boost::units::root;
using boost::units::si::meters;
using boost::units::si::meters_per_second;
using boost::units::si::radians;
using boost::units::si::seconds;

namespace ats {
namespace enviroment {

StreachCalculator::StreachCalculator() :
		initHeight(0.0 * meters), initLatitude(0.0 * meters), initLongitude(
				0.0 * meters), initSpeed(0.0 * meters_per_second), endHeight(
				0.0 * meters), endLatitude(0.0 * meters), endLongitude(
				0.0 * meters), endSpeed(0.0 * meters_per_second) {
}

StreachCalculator::~StreachCalculator() {
}

UnitTime StreachCalculator::calculateTimeInterval() const {
	UnitLength deltaHeight = endHeight - initHeight;
	UnitLength deltaLatitude = endLatitude - initLatitude;
	UnitLength deltaLongitude = endLongitude - initLongitude;
	UnitVelocity deltaSpeed = endSpeed - initSpeed;

	UnitLength distance = root<2>(pow<2>(deltaHeight) + pow<2>(deltaLatitude)
			+ pow<2>(deltaLongitude));

	UnitTime time = (2.0  * distance) / deltaSpeed;
	return time;
}

void StreachCalculator::setEndHeight(const UnitLength endHeight) {
	this->endHeight = endHeight;
}

void StreachCalculator::setEndLatitude(const UnitLength endLatitude) {
	this->endLatitude = endLatitude;
}

void StreachCalculator::setEndLongitude(const UnitLength endLongitude) {
	this->endLongitude = endLongitude;
}

void StreachCalculator::setEndSpeed(const UnitVelocity endSpeed) {
	this->endSpeed = endSpeed;
}

void StreachCalculator::setInitHeight(const UnitLength initHeightFt) {
	this->initHeight = initHeightFt;
}

void StreachCalculator::setInitLatitude(const UnitLength initLatitude) {
	this->initLatitude = initLatitude;
}

void StreachCalculator::setInitLongitude(const UnitLength initLongitude) {
	this->initLongitude = initLongitude;
}

void StreachCalculator::setInitSpeed(const UnitVelocity initSpeed) {
	this->initSpeed = initSpeed;
}

UnitVelocity StreachCalculator::calculateHeightChangeRate() const {
	return (endHeight - initHeight) / calculateTimeInterval();
}

UnitAcceleration StreachCalculator::calculateSpeedChangeRate() const {
	return (endSpeed - initSpeed) / calculateTimeInterval();
}

UnitAngle StreachCalculator::calculateHeading() const {
	UnitLength deltaHeight = endHeight - initHeight;
	UnitLength deltaLatitude = endLatitude - initLatitude;
	UnitLength deltaLongitude = endLongitude - initLongitude;

	UnitAngle angle(0.0 * radians);
	if (deltaLatitude.value() <= 0.0 && deltaLatitude.value() >= 0.0) {
		angle = M_PI * radians - angle;
	} else if (deltaLatitude.value() <= 0.0 && deltaLatitude.value() <= 0.0) {
		angle = M_PI * radians + angle;
	} else if (deltaLatitude.value() >= 0.0 && deltaLatitude.value() <= 0.0) {
		angle = M_PI * radians - angle;
	}

	return angle;
}

UnitLength StreachCalculator::getInitHeight() const {
	return initHeight;
}

UnitVelocity StreachCalculator::getInitSpeed() const {
	return initSpeed;
}

UnitLength StreachCalculator::getInitLatitude() const {
	return initLatitude;
}

UnitLength StreachCalculator::getInitLongitude() const {
	return initLongitude;
}

void StreachCalculator::advance() {
	initHeight = endHeight;
	initLatitude = endLatitude;
	initLongitude = endLongitude;
	initSpeed = endSpeed;
}

} /* namespace enviroment */
} /* namespace ats */
