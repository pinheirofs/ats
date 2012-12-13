#include <boost/units/cmath.hpp>
#include <boost/units/systems/si/time.hpp>

#include "aircraft.h"
#include "converter.h"

using std::vector;

using boost::units::cos;
using boost::units::sin;
using boost::units::si::seconds;

namespace ats {
namespace enviroment {

Aircraft::Aircraft() {
}

Aircraft::~Aircraft() {
}

void Aircraft::setName(std::string name) {
    this->name = name;
}

std::string Aircraft::getName() {
    return name;
}

void Aircraft::removeStretchAt(int index) {
    vector<Stretch>::iterator iterator = stretchs.end();
    iterator += index;
    stretchs.erase(iterator);
}

void Aircraft::setStretchLimitTime(const int index, const UnitTime limitTime) {
    Stretch stretch = stretchs[index];
    stretch.setLimitTime(limitTime);
    stretchs[index] = stretch;
}

UnitTime Aircraft::getStretchLimitTime(const int index) const {
    Stretch stretch = stretchs[index];
    return stretch.getLimitTime();
}

void Aircraft::setStretchHeading(const int index, const UnitAngle heading) {
    Stretch stretch = stretchs[index];
    stretch.setHeading(heading);
    stretchs[index] = stretch;
}

UnitAngle Aircraft::getStretchHeading(const int index) const {
    Stretch stretch = stretchs[index];
    return stretch.getHeading();
}

void Aircraft::setStretchSpeed(const int index, const UnitVelocity speed) {
    Stretch stretch = stretchs[index];
    stretch.setInitSpeed(speed);
    stretchs[index] = stretch;
}

UnitVelocity Aircraft::getStretchSpeed(const int index) const {
    Stretch stretch = stretchs[index];
    return stretch.getInitSpeed();
}

void Aircraft::setStretchInitHeight(const int index, const UnitLength height) {
    Stretch stretch = stretchs[index];
    stretch.setInitHeight(height);
    stretchs[index] = stretch;
}

UnitLength Aircraft::getStretchInitHeight(const int index) const {
    Stretch stretch = stretchs[index];
    return stretch.getInitHeight();
}

int Aircraft::countStretchs() const {
    return stretchs.size();
}

bool Aircraft::isFlying(UnitTime time) {
    Stretch lastStretch = *stretchs.end();

    return lastStretch.getLimitTime() < time;
}

Coordinate Aircraft::evolve(UnitTime time) {
    Stretch stretch;
    UnitTime previusTime(0.0 * seconds);
    vector<Stretch>::iterator iterator = stretchs.begin();
    while (iterator != stretchs.end()) {
        stretch = *iterator;
        if (stretch.getLimitTime() > time) {
            break;
        }

        previusTime = stretch.getLimitTime();
    }

    Converter converter;

    // Calculo do tempo gasto a patir do ultimo ponto.
    UnitTime stretchTime = stretch.getLimitTime() - previusTime;

    // Calculo da distancia percorida a apartir do ultimo ponto, atraves da formula S = S0 + V0 * t + 0.5 * a * t ^ 2
    UnitVelocity initSpeed = stretch.getInitSpeed();
    UnitAcceleration speedChangeRate = stretch.getSpeedChangeRate();
    UnitLength distance = initSpeed * stretchTime + 0.5 * speedChangeRate * stretchTime * stretchTime;

    // Decomposição da distancia percorida em latitude e longitude.
    UnitAngle heading = stretch.getHeading();

    UnitLength distanceLongitude = distance * cos(heading);
    UnitLength newLongitude = stretch.getInitLongitude() + distanceLongitude;

    UnitLength distanceLatitude = distance * sin(heading);
    UnitLength newLatitude = stretch.getInitLatitude() + distanceLatitude;

    // Calculo da alteracao de altitude
    UnitVelocity heightChangeRate = stretch.getHeightChangeRate();
    UnitLength newHeight = stretch.getInitHeight() + heightChangeRate * stretchTime;

    Coordinate coordinate(newLatitude, newLongitude, newHeight);
    return coordinate;
}

} /* namespace enviroment */
} /* namespace ats */
