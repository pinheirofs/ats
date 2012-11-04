#ifndef APPLICATIONCONTROLLER_H_
#define APPLICATIONCONTROLLER_H_

#include <qobject.h>

#include "application.h"

namespace ats {
namespace display {

/*
 *
 */
class ApplicationController: public QObject {
    public:
        ApplicationController(Application *Application);
        virtual ~ApplicationController();

        bool isRunningSimulation();
    private slots:

    private:
        Application *application;
};

} /* namespace display */
} /* namespace ats */
#endif /* APPLICATIONCONTROLLER_H_ */
