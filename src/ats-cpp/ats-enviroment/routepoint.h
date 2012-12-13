#ifndef ROUTEPOINT_H_
#define ROUTEPOINT_H_

#include "typedefs.h"

namespace ats {
namespace enviroment {

/*
 *
 */
class RoutePoint {
    public:
        RoutePoint();
        virtual ~RoutePoint();

        UnitVelocity getSpeed();
        void setSpeed(UnitVelocity speed);
        UnitLength getHeigth();
        void setHeigth(UnitLength heigth);
        UnitLength getLatitude();
        void setLatitude(UnitLength latitude);
        UnitLength getLongitude();
        void setLongitude(UnitLength longitude);

        static const UnitVelocity DEFALUT_SPEED;
        static const UnitLength DEFALUT_HEIGTH;
        static const UnitLength DEFALUT_LATITUDE;
        static const UnitLength DEFALUT_LONGITUDE;

    private:
        UnitVelocity speed;
        UnitLength heigth;

        // a latitude e a distancia em metros na horizontal a partir da linha do equador.
        UnitLength latitude;

        // a latitude e a distancia em metros na horizontal a partir da linha do meridiano de Greenwich.
        UnitLength longitude;
};

} /* namespace enviroment */
} /* namespace ats */
#endif /* ROUTEPOINT_H_ */
