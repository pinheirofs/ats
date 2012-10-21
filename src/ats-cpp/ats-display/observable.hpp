#ifndef OBSERVABLE_HPP_
#define OBSERVABLE_HPP_

#include <vector>

#include "observable.hpp"
#include "observer.hpp"

namespace ats {
namespace display {
namespace util {

/*
 *
 */
class Observable {
    public:
        Observable();
        virtual ~Observable();

        void addObserver(const Observer &observer);
        int  countObserver() const;
        void removeObserver(const Observer &observer);
        void removeAllObservers();
        void notifyObservers();
        void setChanged();
        bool hasChanged() const;

    protected:
        void clearChanged();

    private:
        std::vector<Observer> observers;
        bool changed;
};

} /* namespace util */
} /* namespace display */
} /* namespace ats */
#endif /* OBSERVABLE_HPP_ */
