#define _USE_MATH_DEFINES

#include <cmath>

#include "converter.h"

namespace ats {
namespace enviroment {

const double Converter::NM_IN_FT = 6076.11549;
const double Converter::NM_IN_DEGREES = 0.0166666667;

Converter::Converter() {
}

Converter::~Converter() {
}

double Converter::convertFtToNm(double value_ft) {
    return value_ft / NM_IN_FT;
}

double Converter::convertDegreesToNm(double value_degrees) {
    return value_degrees / NM_IN_DEGREES;
}

double Converter::convertRadianToDegrees(double value_rad) {
    return value_rad * M_PI / 180.0;
}

double Converter::convertDegreesToRadian(double value_deg) {
    return value_deg * 180.0 / M_PI;
}


} /* namespace enviroment */
} /* namespace ats */
