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
        AtsMainWindow();
        virtual ~AtsMainWindow();

    protected:
        void closeEvent(QCloseEvent * event);

    signals:
        void exitApplication();
        void showAddAirtrafficDialog();
        void prepareSimulation();
        void startSimulation();
        bool isRunningSimulation();

    private slots:
        void exitActionTriggered();
        void addAirTraficActionTriggered();
        void prepareSimulationActionTriggered();
        void startSimulationActionTriggered();

    private:
        QAction *exitAction;
        QAction *addAirTraficAction;
        QAction *prepareSimulationAction;
        QAction *startSimulationAction;

        void config();
        void createMenus();
        void createAirTrafficMenu();
        void createSystemMenu();
        void createSimulationMenu();
};

} /* namespace display */
} /* namespace ats */
#endif /* ATSMAINWINDOW_H_ */
