#ifndef AIRTRAFFICMANAGEMENTDIALOG_H_
#define AIRTRAFFICMANAGEMENTDIALOG_H_

#include <qdialog.h>
#include <qlineedit.h>
#include <qtablewidget.h>

namespace ats {
namespace display {

/*
 *
 */
class AirTrafficDialog: public QDialog {
    Q_OBJECT

    public:
        AirTrafficDialog(QWidget *parent);
        virtual ~AirTrafficDialog();

    signals:
        void addRoutePoint(int);
        void removeRoutePoint(int);
        void setTrafficName(const QString &);
        void setTrafficLatitude(int indexRoutePoint, double latitude);
        void setTrafficLongitude(int indexRoutePoint, double longitude);
        void setTrafficHeight(int indexRoutePoint, double height);
        void setTrafficSpeed(int indexRoutePoint, double speed);
        bool isValidTraffic();
        void saveTraffic();

    private slots:
        void nameTextEdited(const QString &name);
        void saveButtonCliecked();
        void removeRoutePointButtonClicked();
        void addRoutePointButtonClicked();
        void routePointTableCellChanged(int row, int column);

    private:
        void config();
        void buildLayout();
        QLayout *createTrafficDetailLayout();
        QLayout *createButtonsLayout();

        double getLatitude(int row) const;
        double getLongitude(int row) const;
        double getSpeed(int row) const;
        double getHeight(int row) const;
        double getDoubleValueFromTable(int row, int column) const;

        QLineEdit *nameLineEdit;
        QTableWidget *routePointTable;
};

} /* namespace display */
} /* namespace ats */
#endif /* AIRTRAFFICMANAGEMENTDIALOG_H_ */
