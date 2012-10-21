#ifndef GUIFACTORY_HPP_
#define GUIFACTORY_HPP_

#include <QObject>

#include "application.hpp"

namespace ats {
namespace display {

class GuiFactory: public QObject {
    Q_OBJECT

    public:
        virtual ~GuiFactory();
        static GuiFactory *getInstance();

        void showAtsMainWindow(Application *application);
    private:
        static GuiFactory *INSTANCE;

        GuiFactory();
};

} /* namespace display */
} /* namespace ats */

#endif /* GUIFACTORY_HPP_ */
