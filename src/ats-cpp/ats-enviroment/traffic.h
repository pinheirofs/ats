#ifndef TRAFFIC_H_
#define TRAFFIC_H_

#include <string>
#include <vector>

#include "routepoint.h"

using std::string;
using std::vector;

namespace ats {
namespace enviroment {

/*
 *
 */
class Traffic {
    public:
        Traffic();
        virtual ~Traffic();

        string getName() const;
        void setName(const string &name);
        void addRoutePointAt(int index);
        void removeRoutePointAt(int index);
        void setRoutePointLatitudeAt(const int index, double latitude);
        void setRoutePointLongitudeAt(const int index, double longitude);
        void setRoutePointSpeedAt(const int index, double speed);
        void setRoutePointHeightAt(const int index, double height);

    private:
        string name;
        vector<RoutePoint> routePoints;
};

} /* namespace enviroment */
} /* namespace ats */
#endif /* TRAFFIC_H_ */
