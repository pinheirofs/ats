#ifndef GUIFACTORY_HPP_
#define GUIFACTORY_HPP_

#include <QObject>

#include "application.hpp"
#include "atsmainwindow.hpp"

namespace ats {
namespace display {

class GuiFactory: public QObject {
    Q_OBJECT

    public:
        virtual ~GuiFactory();
        static GuiFactory *getInstance();

        void showAtsMainWindow();

    private slots:
        void showAirTrafficManagementWindow();

    private:
        static GuiFactory *INSTANCE;

        Application application;
        AtsMainWindow *mainWindow;

        GuiFactory();
};

} /* namespace display */
} /* namespace ats */

#endif /* GUIFACTORY_HPP_ */
