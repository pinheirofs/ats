#include <cmath>

#include "aircraft.h"
#include "converter.h"

using std::cos;
using std::sin;
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
    return aircraftcChangeRate.getHeightChangeRate_ft_ms();
}

void Aircraft::setStretchSpeed_kt(const int index, const double speed_kt) {
    Stretch aircraftcChangeRate = stretchs[index];
    aircraftcChangeRate.setSpeedChangeRate_kt_ms(speed_kt);
    stretchs[index] = aircraftcChangeRate;
}

double Aircraft::getStretchSpeed_kt(const int index) const {
    Stretch aircraftcChangeRate = stretchs[index];
    return aircraftcChangeRate.getSpeedChangeRate_kt_ms();
}

void Aircraft::setStretchHeight_ft(const int index, const double height_ft) {
    Stretch aircraftcChangeRate = stretchs[index];
    aircraftcChangeRate.setHeightChangeRate_ft_ms(height_ft);
    stretchs[index] = aircraftcChangeRate;
}

double Aircraft::getStretchHeight_ft(const int index) const {
    Stretch aircraftcChangeRate = stretchs[index];
    return aircraftcChangeRate.getHeightChangeRate_ft_ms();
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

    Converter converter;

    // Calculo do tempo gasto a patir do ultimo ponto.
    long stretchTime_ms = stretch.getLimitTime_ms() - previusTime;
    double stretchTime_h = converter.convertMillisecondToHour(stretchTime_ms);

    // Calculo da distancia percorida a apartir do ultimo ponto, atraves da formula S = S0 + V0 * t + 0.5 * a * t ^ 2
    double initSpeed_kt = stretch.getInitSpeed_kt();
    double speedChangeRate_kt_ms = stretch.getSpeedChangeRate_kt_ms();
    double distance_nm = initSpeed_kt * stretchTime_h + 0.5 * speedChangeRate_kt_ms * stretchTime_ms * stretchTime_h;

    // Decomposição da distancia percorida em latitude e longitude.
    double heading_rad = converter.convertDegreesToRadian(stretch.getHeading_deg());
    double distanceLongitude_nm = distance_nm * cos(heading_rad);
    double headingLatitude_sin = distance_nm * sin(heading_rad);

    double heightChangeRate = stretch.getHeightChangeRate_ft_ms();


    Coordinate coordinate;
    return coordinate;
}

} /* namespace enviroment */
} /* namespace ats */
