#include "stretch.h"

using boost::units::si::meters;
using boost::units::si::meters_per_second;
using boost::units::si::meters_per_second_squared;
using boost::units::si::radians;
using boost::units::si::second;

namespace ats {
namespace enviroment {

Stretch::Stretch()
        : limitTime(0 * second), heading(0.0 * radians), speedChangeRate(0.0 * meters_per_second_squared), heightChangeRate(0.0 * meters_per_second),
                initSpeed(0.0 * meters_per_second), initHeight(0.0 * meters), initLatitude(0.0 * meters), initLongitude(0.0 * meters) {
}

Stretch::~Stretch() {
}

UnitTime Stretch::getLimitTime() const {
    return limitTime;
}

void Stretch::setLimitTime(const UnitTime limitTime) {
    this->limitTime = limitTime;
}

UnitVelocity Stretch::getHeightChangeRate() const {
    return heightChangeRate;
}

void Stretch::setHeightChangeRate(const UnitVelocity heghtChangeRate) {
    this->heightChangeRate = heghtChangeRate;
}

UnitAngle Stretch::getHeading() const {
    return heading;
}

void Stretch::setHeading(const UnitAngle heading) {
    this->heading = heading;
}

UnitAcceleration Stretch::getSpeedChangeRate() const {
    return speedChangeRate;
}

void Stretch::setSpeedChangeRate(const UnitAcceleration speedChangeRate) {
    this->speedChangeRate = speedChangeRate;
}

UnitVelocity Stretch::getInitSpeed() const {
    return initSpeed;
}

void Stretch::setInitSpeed(const UnitVelocity initSpeed) {
    this->initSpeed = initSpeed;
}

UnitLength Stretch::getInitHeight() const {
	return initHeight;
}

void Stretch::setInitHeight(const UnitLength initHeight) {
	this->initHeight = initHeight;
}

UnitLength Stretch::getInitLatitude() const {
	return initLatitude;
}

void Stretch::setInitLatitude(const UnitLength initLatitude_deg) {
	this->initLatitude = initLatitude_deg;
}

UnitLength Stretch::getInitLongitude() const {
	return initLongitude;
}

void Stretch::setInitLongitude(const UnitLength initLongitude_deg) {
	this->initLongitude = initLongitude_deg;
}

} /* namespace enviroment */
} /* namespace ats */
