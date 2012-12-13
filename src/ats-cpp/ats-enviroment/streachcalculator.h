#ifndef TIMECALCULATOR_H_
#define TIMECALCULATOR_H_

#include "typedefs.h"

namespace ats {
namespace enviroment {

/*
 *
 */
class StreachCalculator {
    public:
        StreachCalculator();
        virtual ~StreachCalculator();

        void setEndHeight(const UnitLength endHeight);
        void setEndLatitude(const UnitLength endLatitude);
        void setEndLongitude(const UnitLength endLongitude);
        void setEndSpeed(const UnitVelocity endSpeed);
        UnitLength getInitHeight() const;
        void setInitHeight(const UnitLength initHeight);
        UnitLength getInitLatitude() const;
        void setInitLatitude(const UnitLength initLatitude);
        UnitLength getInitLongitude() const;
        void setInitLongitude(const UnitLength initLongitude);
        UnitVelocity getInitSpeed() const;
        void setInitSpeed(const UnitVelocity initSpeed);

        UnitTime calculateTimeInterval() const;
        UnitVelocity calculateHeightChangeRate() const;
        UnitAcceleration calculateSpeedChangeRate() const;
        UnitAngle calculateHeading() const;
        void advance();

    private:
        UnitLength initHeight;
        UnitLength initLatitude;
        UnitLength initLongitude;
        UnitVelocity initSpeed;
        UnitLength endHeight;
        UnitLength endLatitude;
        UnitLength endLongitude;
        UnitVelocity endSpeed;
};

} /* namespace enviroment */
} /* namespace ats */
#endif /* TIMECALCULATOR_H_ */
