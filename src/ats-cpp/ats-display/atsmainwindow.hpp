#ifndef ATSMAINWINDOW_HPP_
#define ATSMAINWINDOW_HPP_

#include <qaction.h>
#include <qevent.h>
#include <qmainwindow.h>

#include "applicationcontroller.hpp"
#include "observer.hpp"

namespace ats {
namespace display {

/*
 *
 */
class AtsMainWindow: public QMainWindow, public util::Observer {
    Q_OBJECT

    public:
        AtsMainWindow(ApplicationController *controller);
        virtual ~AtsMainWindow();
        virtual void notify();

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
#endif /* ATSMAINWINDOW_HPP_ */
