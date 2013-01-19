#ifndef SIMULATIONTEST_H_
#define SIMULATIONTEST_H_

#include <qtest.h>

#include "aircraft.h"

class SimulationTest : public QObject {
Q_OBJECT
    ;

public:
    SimulationTest();
    virtual ~SimulationTest();

private slots:
    void createEmptySimulationTest();
    void addAircraftsTest();
    void clearAircraftsTest();
    void sleepTimeTest();
    void addSimulationListenersTest();
};

#endif /* SIMULATIONTEST_H_ */
