#ifndef TRAFFIC_H_
#define TRAFFIC_H_

#include <string>
#include <vector>

#include "routepoint.h"

namespace ats {
namespace enviroment {

/*
 *
 */
class Traffic {
    public:
        Traffic();
        virtual ~Traffic();

        std::string getName() const;
        void setName(const std::string &name);
        void addRoutePointAt(int index);
        void removeRoutePointAt(int index);
        void setRoutePointLatitude_degrees(const int index, double latitude_degrees);
        double getRoutePointLatitude_degrees(const int index) const;
        void setRoutePointLongitude_degrees(const int index, double longitude_degrees);
        double getRoutePointLongitude_degrees(const int index) const;
        void setRoutePointSpeed_kt(const int index, double speed_kt);
        double getRoutePointSpeed_kt(const int index) const;
        void setRoutePointHeight_ft(const int index, double height_ft);
        double getRoutePointHeight_ft(const int index) const;
        int countRoutePoints() const;

    private:
        std::string name;
        std::vector<RoutePoint> routePoints;
};

} /* namespace enviroment */
} /* namespace ats */
#endif /* TRAFFIC_H_ */
