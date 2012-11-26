#include "stretch.h"

namespace ats {
namespace enviroment {

Stretch::Stretch()
        : limitTime_ms(0), heading_degrees(0.0), speedChangeRate_kt_ms2(0.0), heightChangeRate_ft_ms(0.0),
                initSpeed_kt_ms(0.0) {
}

Stretch::~Stretch() {
}

long Stretch::getLimitTime_ms() const {
    return limitTime_ms;
}

void Stretch::setLimitTime_ms(const long limitTime_ms) {
    this->limitTime_ms = limitTime_ms;
}

double Stretch::getHeightChangeRate_ft() const {
    return heightChangeRate_ft_ms;
}

void Stretch::setHeightChangeRate_ft_ms(const double heghtChangeRate_ft_ms) {
    this->heightChangeRate_ft_ms = heghtChangeRate_ft_ms;
}

double Stretch::getHeading_deg() {
    return heading_degrees;
}

void Stretch::setHeading_deg(const double heading_degrees) {
    this->heading_degrees = heading_degrees;
}

double Stretch::getSpeedChangeRate_kt_ms2() const {
    return speedChangeRate_kt_ms2;
}

void Stretch::setSpeedChangeRate_kt_ms2(const double speedChangeRateKt) {
    speedChangeRate_kt_ms2 = speedChangeRateKt;
}

double Stretch::getInitSpeed_kt_ms() const {
    return initSpeed_kt_ms;
}

void Stretch::setInitSpeed_kt_ms(const double initSpeed_kt_ms) {
    this->initSpeed_kt_ms = initSpeed_kt_ms;
}

} /* namespace enviroment */
} /* namespace ats */
