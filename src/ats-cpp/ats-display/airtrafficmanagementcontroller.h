#ifndef AIRTRAFFICMANAGEMENTCONTROLLER_H_
#define AIRTRAFFICMANAGEMENTCONTROLLER_H_

#include <string>
#include <vector>

#include <qobject.h>

#include <traffic.h>
#include "application.h"

namespace ats {
namespace display {

/*
 *
 */
class AirTrafficManagementController: public QObject {
    Q_OBJECT

    public:
        AirTrafficManagementController(Application *);
        virtual ~AirTrafficManagementController();

    public slots:
        void setTrafficName(const QString &);
        void setTrafficLatitude(int indexRoutePoint, double latitude);
        void setTrafficLongitude(int indexRoutePoint, double longitude);
        void setTrafficHeight(int indexRoutePoint, double height);
        void setTrafficSpeed(int indexRoutePoint, double speed);
        void saveTraffic();
        void addRoutePoint(int index);
        void removeRoutePoint(int index);

    private:
        ats::enviroment::Traffic traffic;
        Application *application;

};

} /* namespace display */
} /* namespace ats */
#endif /* AIRTRAFFICMANAGEMENTCONTROLLER_H_ */
