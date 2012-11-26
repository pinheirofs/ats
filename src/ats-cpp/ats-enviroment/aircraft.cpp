#include "aircraft.h"

using std::vector;

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

void Aircraft::setStretchLimitTime_ms(const int index, const long limitTime_ms) {
    Stretch aircraftcChangeRate = stretchs[index];
    aircraftcChangeRate.setLimitTime_ms(limitTime_ms);
    stretchs[index] = aircraftcChangeRate;
}

long Aircraft::getStretchLimitTime_ms(const int index) const {
    Stretch aircraftcChangeRate = stretchs[index];
    return aircraftcChangeRate.getLimitTime_ms();
}

void Aircraft::setStretchHeading_degrees(const int index, const double heading_degrees) {
    Stretch aircraftcChangeRate = stretchs[index];
    aircraftcChangeRate.setHeading_deg(heading_degrees);
    stretchs[index] = aircraftcChangeRate;
}

double Aircraft::getStretchHeading_degrees(const int index) const {
    Stretch aircraftcChangeRate = stretchs[index];
    return aircraftcChangeRate.getHeightChangeRate_ft();
}

void Aircraft::setStretchSpeed_kt(const int index, const double speed_kt) {
    Stretch aircraftcChangeRate = stretchs[index];
    aircraftcChangeRate.setSpeedChangeRate_kt_ms2(speed_kt);
    stretchs[index] = aircraftcChangeRate;
}

double Aircraft::getStretchSpeed_kt(const int index) const {
    Stretch aircraftcChangeRate = stretchs[index];
    return aircraftcChangeRate.getSpeedChangeRate_kt_ms2();
}

void Aircraft::setStretchHeight_ft(const int index, const double height_ft) {
    Stretch aircraftcChangeRate = stretchs[index];
    aircraftcChangeRate.setHeightChangeRate_ft_ms(height_ft);
    stretchs[index] = aircraftcChangeRate;
}

double Aircraft::getStretchHeight_ft(const int index) const {
    Stretch aircraftcChangeRate = stretchs[index];
    return aircraftcChangeRate.getHeightChangeRate_ft();
}

int Aircraft::countStretchs() const {
    return stretchs.size();
}

bool Aircraft::isFlying(long time_ms) {
    Stretch lastStretch = *stretchs.end();

    return lastStretch.getLimitTime_ms() < time_ms;
}

Coordinate Aircraft::evolve(long time_ms) {
    Stretch stretch;
    long previusTime = 0;
    vector<Stretch>::iterator iterator = stretchs.begin();
    while (iterator != stretchs.end()) {
        stretch = *iterator;
        if (stretch.getLimitTime_ms() > time_ms) {
            break;
        }

        previusTime = stretch.getLimitTime_ms();
    }

    long stretchTime = stretch.getLimitTime_ms() - previusTime;

    double initSpeed_kt_ms = stretch.getInitSpeed_kt_ms();
    double speedChangeRate_kt_ms2 = stretch.getSpeedChangeRate_kt_ms2();
    double distance = initSpeed_kt_ms * stretchTime + speedChangeRate_kt_ms2 * stretchTime * stretchTime * 0.5;
}

} /* namespace enviroment */
} /* namespace ats */
