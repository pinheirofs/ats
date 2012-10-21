#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

#include "application.hpp"

namespace ats {
namespace display {

/*
 *
 */
class Application {
    public:
        Application(Application *application);
        virtual ~Application();

    private:
        Application *application;
};

} /* namespace display */
} /* namespace ats */
#endif /* APPLICATION_HPP_ */
