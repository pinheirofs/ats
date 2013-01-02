#include "simulationtest.h"

//QTEST_MAIN(SimulationTest);

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    SimulationTest tc;
    return QTest::qExec(&tc, argc, argv);
}
