/*
 * SimulationTest.cpp
 *
 *  Created on: Jan 1, 2013
 *      Author: felipe
 */

#include "aircraft.h"
#include "simulation.h"
#include "simulationtest.h"

using ats::enviroment::Aircraft;
using ats::enviroment::Simulation;

SimulationTest::SimulationTest() {
	// TODO Auto-generated constructor stub

}

SimulationTest::~SimulationTest() {
	// TODO Auto-generated destructor stub
}

void SimulationTest::addAircrafts() {
    Simulation simulation;

    int size = simulation.getAllAircrafts().size();
    QCOMPARE(size, 0);

    Aircraft aicratf;
    aicratf.setName("Aircraft 01");
}
