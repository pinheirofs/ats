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
    void addAircrafts();

};

#endif /* SIMULATIONTEST_H_ */
