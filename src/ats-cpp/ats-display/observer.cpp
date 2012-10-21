#include "observer.hpp"

namespace ats {
namespace display {
namespace util {

Observer::Observer() {
}

Observer::~Observer() {
}

void Observer::notify() {
}

bool Observer::operator==(const Observer &other) {
    return this == &other;
}

} /* namespace util */
} /* namespace display */
} /* namespace ats */
