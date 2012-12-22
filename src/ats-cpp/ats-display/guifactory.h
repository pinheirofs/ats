#ifndef GUIFACTORY_H_
#define GUIFACTORY_H_

#include <QObject>

#include "application.h"
#include "atsmainwindow.h"

namespace ats {
namespace display {

class GuiFactory: public QObject {
    Q_OBJECT;

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

#endif /* GUIFACTORY_H_ */
