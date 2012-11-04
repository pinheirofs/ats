#ifndef ATSMAINWINDOW_H_
#define ATSMAINWINDOW_H_

#include <qaction.h>
#include <qevent.h>
#include <qmainwindow.h>

#include "applicationcontroller.h"

namespace ats {
namespace display {

/*
 *
 */
class AtsMainWindow: public QMainWindow {
    Q_OBJECT

    public:
        AtsMainWindow(ApplicationController *controller);
        virtual ~AtsMainWindow();

        QAction *getExitAction();
        QAction *getAirTrafficManagementAction();

    protected:
        void closeEvent(QCloseEvent * event);

    private slots:

    private:
        ApplicationController *controller;

        QAction *exitAction;
        QAction *airTraficManagementAction;

        void config();
        void createMenus();
};

} /* namespace display */
} /* namespace ats */
#endif /* ATSMAINWINDOW_H_ */
