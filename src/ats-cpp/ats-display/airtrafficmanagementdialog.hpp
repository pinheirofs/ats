#ifndef AIRTRAFFICMANAGEMENTDIALOG_HPP_
#define AIRTRAFFICMANAGEMENTDIALOG_HPP_

#include <qgroupbox.h>
#include <qcombobox.h>
#include <qdialog.h>
#include <qlineedit.h>
#include <qtablewidget.h>

#include "airtrafficmanagementcontroller.hpp"
#include "observer.hpp"

using ats::display::util::Observer;

namespace ats {
namespace display {

/*
 *
 */
class AirTrafficManagementDialog: public QDialog, public Observer {
    Q_OBJECT

    public:
        AirTrafficManagementDialog(QWidget *parent, AirTrafficManagementController *controller);
        virtual ~AirTrafficManagementDialog();

    private slots:
        void updateDetail(QString selectedId);
        void addRoutePoint();
        void removeRoutePoint();

    private:
        AirTrafficManagementController *controller;

        QComboBox *trafficComboBox;
        QGroupBox* detailGroupBox;
        QLineEdit *identificationLineText;
        QTableWidget *routeTable;
        QPushButton *addRoutePointButton;
        QPushButton *removeRoutePointButton;
        QPushButton *saveButton;

        void config();

        void createLayout();
        void createSelectTrafficGroupBox();
        void createTrafficDetailGroupBox();
        void createButtons();

        void loadTrafficComboBox();
};

} /* namespace display */
} /* namespace ats */
#endif /* AIRTRAFFICMANAGEMENTDIALOG_HPP_ */
