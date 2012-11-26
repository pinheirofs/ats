#include <cmath>

#include "streachcalculator.h"
#include "converter.h"

using std::atan2;
using std::pow;
using std::sqrt;

namespace ats {
namespace enviroment {

StreachCalculator::StreachCalculator()
        : initHeight_ft(0.0), initLatitude_degrees(0.0), initLongitude_degrees(0.0), initSpeed_kt(0.0),
                endHeight_ft(0.0), endLatitude_degrees(0.0), endLongitude_degrees(0.0), endSpeed_kt(0.0) {
}

StreachCalculator::~StreachCalculator() {
}

long StreachCalculator::calculateTimeInterval_ms() const {
    double deltaHeight_ft = endHeight_ft - initHeight_ft;
    double deltaLatitude_degrees = endLatitude_degrees - initLatitude_degrees;
    double deltaLongitude_degrees = endLongitude_degrees - initLongitude_degrees;
    double deltaSpeed_kt = endSpeed_kt - initSpeed_kt;

    Converter converter;
    double deltaHeight_nm = converter.convertFtToNm(deltaHeight_ft);
    double deltaLatitude_nm = converter.convertDegreesToNm(deltaLatitude_degrees);
    double deltaLongitude_nm = converter.convertDegreesToNm(deltaLongitude_degrees);

    double temp = pow(deltaHeight_nm, 2.0) + pow(deltaLatitude_nm, 2.0) + pow(deltaLongitude_nm, 2.0);
    double distance_nm = sqrt(static_cast<long double>(temp));

    double time_ms = ((2.0 * distance_nm) / deltaSpeed_kt) * 3600000;
    return static_cast<long>(time_ms);
}

void StreachCalculator::setEndHeight_ft(const double endHeight_ft) {
    this->endHeight_ft = endHeight_ft;
}

void StreachCalculator::setEndLatitude_degrees(const double endLatitude_degrees) {
    this->endLatitude_degrees = endLatitude_degrees;
}

void StreachCalculator::setEndLongitude_degrees(const double endLongitude_degrees) {
    this->endLongitude_degrees = endLongitude_degrees;
}

void StreachCalculator::setEndSpeed_kt(const double endSpeed_kt) {
    this->endSpeed_kt = endSpeed_kt;
}

void StreachCalculator::setInitHeight_ft(const double initHeightFt) {
    this->initHeight_ft = initHeightFt;
}

void StreachCalculator::setInitLatitude_degrees(const double initLatitude_degrees) {
    this->initLatitude_degrees = initLatitude_degrees;
}

void StreachCalculator::setInitLongitude_degrees(const double initLongitude_degrees) {
    this->initLongitude_degrees = initLongitude_degrees;
}

void StreachCalculator::setInitSpeed_kt(const double initSpeed_kt) {
    this->initSpeed_kt = initSpeed_kt;
}

double StreachCalculator::calculateHeightChangeRate_ft_ms() const {
    return (endHeight_ft - initHeight_ft) / calculateTimeInterval_ms();
}

double StreachCalculator::calculateSpeedChangeRate_kt_ms2() const {
    return (endSpeed_kt - initSpeed_kt) / calculateTimeInterval_ms();
}

double StreachCalculator::calculateHeading_degrees() const {
    double deltaLatitude = endLatitude_degrees - initLatitude_degrees;
    double deltaLongitude = endLongitude_degrees - initLongitude_degrees;

    if (deltaLatitude == 0.0 && deltaLongitude == 0.0) {
        return 0.0;
    }

    double angle = atan2(deltaLatitude, deltaLongitude);
    if (deltaLatitude <= 0.0 && deltaLatitude >= 0.0) {
        angle = 360.0 - angle;
    } else if (deltaLatitude <= 0.0 && deltaLatitude <= 0.0) {
        angle = 180.0 + angle;
    } else if (deltaLatitude >= 0.0 && deltaLatitude <= 0.0) {
        angle = 180.0 - angle;
    }

    return angle;
}

void StreachCalculator::advance() {
    initHeight_ft = endHeight_ft;
    initLatitude_degrees = endLatitude_degrees;
    initLongitude_degrees = endLongitude_degrees;
    initSpeed_kt = endSpeed_kt;
}

} /* namespace enviroment */
} /* namespace ats */
