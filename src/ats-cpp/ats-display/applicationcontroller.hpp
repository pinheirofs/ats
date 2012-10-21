#ifndef APPLICATIONCONTROLLER_HPP_
#define APPLICATIONCONTROLLER_HPP_

#include <qobject.h>

#include "application.hpp"
#include "observable.hpp"

using namespace ats::display::util;

namespace ats {
namespace display {

/*
 *
 */
class ApplicationController: public QObject, public Observable {
    public:
        ApplicationController(Application *Application);
        virtual ~ApplicationController();

    private slots:

    private:
        Application *application;
};

} /* namespace display */
} /* namespace ats */
#endif /* APPLICATIONCONTROLLER_HPP_ */
