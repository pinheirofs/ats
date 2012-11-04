#include "application.h"

using std::vector;
using ats::enviroment::Traffic;

namespace ats {
namespace display {

Application::Application() {
    // sem implemetacao
}

Application::~Application() {
    // sem implemetacao
}

vector<Traffic> Application::getAllTraffics() const {
    return traffics;
}

void Application::addTraffic(const ats::enviroment::Traffic &newTraffic) {
    traffics.push_back(newTraffic);
}

} /* namespace display */
} /* namespace ats */
