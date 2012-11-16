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
class AirTrafficController: public QObject {
    Q_OBJECT

    public:
        AirTrafficController(Application *);
        virtual ~AirTrafficController();

    public slots:
        void addRoutePoint(int index);
        void removeRoutePoint(int index);
        void setTrafficName(const QString &);
        void setTrafficLatitude(int indexRoutePoint, double latitude);
        void setTrafficLongitude(int indexRoutePoint, double longitude);
        void setTrafficHeight(int indexRoutePoint, double height);
        void setTrafficSpeed(int indexRoutePoint, double speed);
        bool isValidTraffic();
        void saveTraffic();

    private:
        ats::enviroment::Traffic traffic;
        Application *application;

};

} /* namespace display */
} /* namespace ats */
#endif /* AIRTRAFFICMANAGEMENTCONTROLLER_H_ */
