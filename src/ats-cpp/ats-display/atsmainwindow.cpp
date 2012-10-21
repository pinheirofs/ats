#include "atsmainwindow.hpp"

namespace ats {
namespace display {

AtsMainWindow::AtsMainWindow(ApplicationController *controller) : controller(controller) {
    config();
    createLayout();
}

AtsMainWindow::~AtsMainWindow() {
    delete controller;
}

void AtsMainWindow::config() {
    setWindowTitle(tr("ATS - Air Traffic Simulation"));
    setMinimumSize(800, 600);
}
void AtsMainWindow::createLayout() {

}

void AtsMainWindow::notify() {

}

} /* namespace display */
} /* namespace ats */
