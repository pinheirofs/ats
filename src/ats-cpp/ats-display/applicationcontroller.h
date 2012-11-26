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
    public:
        ApplicationController(Application *Application);
        virtual ~ApplicationController();


    public slots:
        bool isRunningSimulation();
        void prepareSimulation();
        void startSimulation();

    private:
        Application *application;
        ats::enviroment::Simulation simulation;

};

} /* namespace display */
} /* namespace ats */
#endif /* APPLICATIONCONTROLLER_H_ */
