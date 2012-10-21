#include "observable.hpp"

namespace ats {
namespace display {
namespace util {

Observable::Observable() : changed(false) {
}

Observable::~Observable() {
}

void Observable::addObserver(const Observer& observer) {
    observers.push_back(observer);
}

int Observable::countObserver() const {
    return observers.size();
}

void Observable::removeObserver(const Observer& observer) {
    std::vector<Observer>::iterator iterator = observers.begin();
    while (iterator != observers.end()) {
        Observer tempObserver = *iterator;
        if (tempObserver == observer) {
            observers.erase(iterator);
        }

        ++iterator;
    }
}

void Observable::removeAllObservers() {
    observers.clear();
}

void Observable::notifyObservers() {
    std::vector<Observer>::iterator iterator = observers.begin();
    while (iterator != observers.end()) {
        Observer observer = *iterator;
        observer.notify();
        ++iterator;
    }

    changed = false;
}

void Observable::setChanged() {
    changed = true;
}

bool Observable::hasChanged() const {
    return changed;
}

void Observable::clearChanged() {
    changed = false;
}

} /* namespace util */
} /* namespace display */
} /* namespace ats */
