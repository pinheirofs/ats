#define _USE_MATH_DEFINES

#include <cmath>

#include "converter.h"

namespace ats {
namespace enviroment {

const double Converter::NM_IN_FT = 6076.11549;
const double Converter::NM_IN_DEG = 0.0166666667;
const double Converter::MS_IN_HOUR = 3600000.0;

Converter::Converter() {
}

Converter::~Converter() {
}

double Converter::convertFtToNm(double value_ft) const {
    return value_ft / NM_IN_FT;
}

double Converter::convertDegreesToNm(double value_degrees) const {
    return value_degrees / NM_IN_DEG;
}

double Converter::convertRadianToDegrees(double value_rad) const {
    return value_rad * M_PI / 180.0;
}

double Converter::convertDegreesToRadian(double value_deg) const {
    return value_deg * 180.0 / M_PI;
}

double Converter::convertMillisecondToHour(double value_ms) const {
	return value_ms / MS_IN_HOUR;
}

} /* namespace enviroment */
} /* namespace ats */
