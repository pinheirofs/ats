#ifndef AIRCRAFTCCHANGERATE_H_
#define AIRCRAFTCCHANGERATE_H_

#include "typedefs.h"

namespace ats {
namespace enviroment {

/*
 *
 */
class Stretch {
    public:
        Stretch();
        virtual ~Stretch();

        UnitTime getLimitTime() const;
        void setLimitTime(const UnitTime limitTime);
        UnitAngle getHeading() const;
        void setHeading(const UnitAngle heading);
        UnitAcceleration getSpeedChangeRate() const;
        void setSpeedChangeRate(const UnitAcceleration speedChangeRate);
        UnitVelocity getHeightChangeRate() const;
        void setHeightChangeRate(const UnitVelocity heghtChangeRate);
        UnitVelocity getInitSpeed() const;
        void setInitSpeed(const UnitVelocity initSpeed);
        UnitLength getInitHeight() const;
        void setInitHeight(const UnitLength initHeight);
        UnitLength getInitLatitude() const;
        void setInitLatitude(const UnitLength initLatitude);
        UnitLength getInitLongitude() const;
        void setInitLongitude(const UnitLength initLongitude);

    private:
        UnitTime limitTime;
        UnitAngle heading;
        UnitAcceleration speedChangeRate;
        UnitVelocity heightChangeRate;
        UnitVelocity initSpeed;
        UnitLength initHeight;
        UnitLength initLatitude;
        UnitLength initLongitude;
};

} /* namespace enviroment */
} /* namespace ats */
#endif /* AIRCRAFTCCHANGERATE_H_ */
