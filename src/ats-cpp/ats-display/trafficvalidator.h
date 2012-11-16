#ifndef TRAFFICVALIDATOR_H_
#define TRAFFICVALIDATOR_H_

#include "traffic.h"

namespace ats {
namespace enviroment {

/*
 *
 */
class TrafficValidator {
    public:
        TrafficValidator();
        virtual ~TrafficValidator();

        void setTraffic(const Traffic traffic);
        bool isValid() const;

        static const double HEIGTH_MAX_FT;
        static const double HEIGTH_MIN_FT;
        static const double LATITUDE_MAX_DEGREES;
        static const double LATITUDE_MIN_DEGREES;
        static const double LONGITUDE_MAX_DEGREES;
        static const double LONGITUDE_MIN_DEGREES;
        static const double SPEED_MAX_KT;
        static const double SPEED_MIN_KT;

    private:
        Traffic traffic;
};

} /* namespace enviroment */
} /* namespace ats */
#endif /* TRAFFICVALIDATOR_H_ */
