#ifndef APPLICATIONCONTROLLER_H_
#define APPLICATIONCONTROLLER_H_

#include <qobject.h>

#include "application.h"
#include "simulation.h"

namespace ats {
namespace display {

/*
 *
 */
class ApplicationController: public QObject {
    Q_OBJECT;

    public:
        ApplicationController(Application *Application);
        virtual ~ApplicationController();

    public slots:
        void prepareSimulation();
        void startSimulation();
        bool isRunningSimulation();

    private:
        Application *application;
        ats::enviroment::Simulation simulation;

};

} /* namespace display */
} /* namespace ats */
#endif /* APPLICATIONCONTROLLER_H_ */
