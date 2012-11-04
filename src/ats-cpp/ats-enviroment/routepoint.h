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

        int getId();
        void setId(int id);
        double getSpeed_mn();
        void setSpeed_mn(double speed_mn);
        double getHeigth_ft();
        void setHeigth_ft(double heigth_ft);
        double getLatitude_degrees();
        void setLatitude_degrees(double latitude_degrees);
        double getLongitude_degrees();
        void setLongitude_degrees(double longitude_degrees);

        bool operator==(const RoutePoint & other);

    private:
        int id;
        double speed_mn;
        double heigth_ft;
        double latitude_degrees;
        double longitude_degrees;
};

} /* namespace enviroment */
} /* namespace ats */
#endif /* ROUTEPOINT_H_ */
