#ifndef TRAFFIC_H_
#define TRAFFIC_H_

#include <string>
#include <vector>

#include "routepoint.h"
#include "typedefs.h"

namespace ats {
namespace enviroment {

class Traffic {
    public:
        Traffic();
        virtual ~Traffic();

        std::string getName() const;
        void setName(const std::string &name);
        void addRoutePointAt(int index);
        void removeRoutePointAt(int index);
        void setRoutePointLatitude(const int index, UnitLength latitude);
        UnitLength getRoutePointLatitude(const int index) const;
        void setRoutePointLongitude(const int index, UnitLength longitude);
        UnitLength getRoutePointLongitude(const int index) const;
        void setRoutePointSpeed(const int index, UnitVelocity speed);
        UnitVelocity getRoutePointSpeed(const int index) const;
        void setRoutePointHeight(const int index, UnitLength height);
        UnitLength getRoutePointHeight(const int index) const;
        int countRoutePoints() const;

    private:
        std::string name;
        std::vector<RoutePoint> routePoints;
};

} /* namespace enviroment */
} /* namespace ats */
#endif /* TRAFFIC_H_ */
