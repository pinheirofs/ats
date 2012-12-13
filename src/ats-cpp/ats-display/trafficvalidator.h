#ifndef TRAFFICVALIDATOR_H_
#define TRAFFICVALIDATOR_H_

#include "traffic.h"
#include "typedefs.h"

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

        static const UnitLength HEIGTH_MAX;
        static const UnitLength HEIGTH_MIN;
        static const UnitLength LATITUDE_MAX;
        static const UnitLength LATITUDE_MIN;
        static const UnitLength LONGITUDE_MAX;
        static const UnitLength LONGITUDE_MIN;
        static const UnitVelocity SPEED_MAX;
        static const UnitVelocity SPEED_MIN;

    private:
        Traffic traffic;
};

} /* namespace enviroment */
} /* namespace ats */
#endif /* TRAFFICVALIDATOR_H_ */
