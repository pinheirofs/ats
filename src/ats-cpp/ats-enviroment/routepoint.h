#ifndef ROUTEPOINT_H_
#define ROUTEPOINT_H_

namespace ats {
namespace enviroment {

/*
 *
 */
class RoutePoint {
    public:
        RoutePoint();
        virtual ~RoutePoint();

        double getSpeed_kt();
        void setSpeed_kt(double speed_mn);
        double getHeigth_ft();
        void setHeigth_ft(double heigth_ft);
        double getLatitude_degrees();
        void setLatitude_degrees(double latitude_degrees);
        double getLongitude_degrees();
        void setLongitude_degrees(double longitude_degrees);

        static const double DEFALUT_SPEED_KT;
        static const double DEFALUT_HEIGTH_FT;
        static const double DEFALUT_LATITUDE_DEGREES;
        static const double DEFALUT_LONGITUDE_DEGREES;

    private:
        double speed_kt;
        double heigth_ft;
        double latitude_degrees;
        double longitude_degrees;
};

} /* namespace enviroment */
} /* namespace ats */
#endif /* ROUTEPOINT_H_ */
