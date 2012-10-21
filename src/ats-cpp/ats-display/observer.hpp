#ifndef OBSERVER_HPP_
#define OBSERVER_HPP_

namespace ats {
namespace display {
namespace util {

/*
 *
 */
class Observer {
    public:
        Observer();
        virtual ~Observer();

        virtual void notify();
        bool operator==(const Observer &other);
};

} /* namespace util */
} /* namespace display */
} /* namespace ats */


#endif /* OBSERVER_HPP_ */
