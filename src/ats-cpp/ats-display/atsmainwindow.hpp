#ifndef ATSMAINWINDOW_HPP_
#define ATSMAINWINDOW_HPP_

#include <qmainwindow.h>

#include "applicationcontroller.hpp"
#include "observer.hpp"

namespace ats {
namespace display {

/*
 *
 */
class AtsMainWindow: public QMainWindow, public util::Observer {
    Q_OBJECT

    public:
        AtsMainWindow(ApplicationController *controller);
        virtual ~AtsMainWindow();
        virtual void notify();

    private:
        ApplicationController *controller;

        void config();
        void createLayout();
};

} /* namespace display */
} /* namespace ats */
#endif /* ATSMAINWINDOW_HPP_ */
