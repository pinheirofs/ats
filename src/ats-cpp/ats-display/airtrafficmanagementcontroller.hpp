#ifndef AIRTRAFFICMANAGEMENTCONTROLLER_HPP_
#define AIRTRAFFICMANAGEMENTCONTROLLER_HPP_

#include <string>
#include <vector>

#include "application.hpp"
#include "observable.hpp"

using std::string;
using std::vector;

using ats::display::util::Observable;

namespace ats {
namespace display {

/*
 *
 */
class AirTrafficManagementController : public Observable {
    public:
        AirTrafficManagementController(Application *application);
        virtual ~AirTrafficManagementController();

        vector<string> *getTrafficIds();
};

} /* namespace display */
} /* namespace ats */
#endif /* AIRTRAFFICMANAGEMENTCONTROLLER_HPP_ */
