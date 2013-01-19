/*
 * SimulationTest.cpp
 *
 *  Created on: Jan 1, 2013
 *      Author: felipe
 */

#include <aircraft.h>
#include <simulation.h>
#include <simulationlistener.h>
#include <typedefs.h>

#include "simulationtest.h"

using ats::enviroment::Aircraft;
using ats::enviroment::Simulation;
using ats::enviroment::SimulationListener;
using ats::enviroment::UnitTime;

SimulationTest::SimulationTest() {
}

SimulationTest::~SimulationTest() {
}

void SimulationTest::createEmptySimulationTest() {
    Simulation simulation;

    int quantityAircrafts = simulation.quantityAircrafts();
    QCOMPARE(quantityAircrafts, 0);

    int quantitySimulationListeners = simulation.quantitySimulationListeners();
    QCOMPARE(quantitySimulationListeners, 0);
}

void SimulationTest::addAircraftsTest() {
    Aircraft aircratf01, aircratf02, aircratf03;
    aircratf01.setName("Aircraft 01");
    aircratf02.setName("Aircraft 02");
    aircratf03.setName("Aircraft 03");

    Simulation simulation;
    simulation.addAircraft(aircratf01);
    simulation.addAircraft(aircratf02);
    simulation.addAircraft(aircratf03);

    int quantityAircrafts = simulation.quantityAircrafts();
    QCOMPARE(quantityAircrafts, 3);
}

void SimulationTest::clearAircraftsTest() {
    Aircraft aircratf01, aircratf02, aircratf03;
    aircratf01.setName("Aircraft 01");
    aircratf02.setName("Aircraft 02");
    aircratf03.setName("Aircraft 03");

    Simulation simulation;
    simulation.addAircraft(aircratf01);
    simulation.addAircraft(aircratf02);
    simulation.addAircraft(aircratf03);

    simulation.clearAircrafts();

    int quantityAircrafts = simulation.quantityAircrafts();
    QCOMPARE(quantityAircrafts, 0);
}

void SimulationTest::sleepTimeTest() {
    Simulation simulation;

    UnitTime initSleepTime(1.0 * boost::units::si::second);
    simulation.setSleepTime(initSleepTime);

    UnitTime finalSleepTime = simulation.getSleepTime();
    QCOMPARE(initSleepTime, finalSleepTime);
}

void SimulationTest::addSimulationListenersTest() {
    SimulationListener simulationListener01, simulationListener02;

    Simulation simulation;
    simulation.addSimulationListener(simulationListener01);
    simulation.addSimulationListener(simulationListener02);

    int quantitySimulationListeners = simulation.quantitySimulationListeners();
    QCOMPARE(quantitySimulationListeners, 2);
}
