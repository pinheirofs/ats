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

    protected:
        void closeEvent(QCloseEvent * event);

    signals:
        void exitApplication();
        void showAddAirtrafficDialog();

    private slots:
        void exitActionTriggered();
        void addAirTraficActionTriggered();

    private:
        ApplicationController *controller;

        QAction *exitAction;
        QAction *addAirTraficAction;

        void config();
        void createMenus();
};

} /* namespace display */
} /* namespace ats */
#endif /* ATSMAINWINDOW_H_ */
