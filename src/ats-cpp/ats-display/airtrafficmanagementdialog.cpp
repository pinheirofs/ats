#include <limits>
#include <string>
#include <vector>

#include <qboxlayout.h>
#include <qgridlayout.h>
#include <qheaderview.h>
#include <qheaderview.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qsizepolicy.h>

#include "airtrafficmanagementdialog.h"
#include "airtrafficmanagementcontroller.h"

namespace ats {
namespace display {

using namespace std;

AirTrafficManagementDialog::AirTrafficManagementDialog(QWidget *parent)
        : QDialog(parent), nameLineEdit(0), routePointTable(0) {
    config();
    buildLayout();
}

void AirTrafficManagementDialog::buildLayout() {
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(createTrafficDetailLayout());
    mainLayout->addLayout(createButtonsLayout());

    setLayout(mainLayout);
}
QLayout *AirTrafficManagementDialog::createButtonsLayout() {
    QHBoxLayout *layout = new QHBoxLayout();
    layout->setAlignment(Qt::AlignRight);

    QPushButton *saveButton = new QPushButton(tr("Save"));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveButtonCliecked()));
    layout->addWidget(saveButton);

    return layout;
}

void AirTrafficManagementDialog::saveButtonCliecked() {
    saveTraffic();
}

QLayout *AirTrafficManagementDialog::createTrafficDetailLayout() {
    QVBoxLayout *baseLayout = new QVBoxLayout();

    QHBoxLayout *nameLayout = new QHBoxLayout();
    baseLayout->addLayout(nameLayout);

    QLabel *nameLabel = new QLabel(tr("Name"));
    nameLayout->addWidget(nameLabel);

    nameLineEdit = new QLineEdit();
    nameLineEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    connect(nameLineEdit, SIGNAL(textEdited(const QString &)), this, SLOT(nameTextEdited(const QString &)));
    nameLayout->addWidget(nameLineEdit);

    QStringList columnNames;
    columnNames.append(trUtf8("Latitude (°)"));
    columnNames.append(trUtf8("Longitude (°)"));
    columnNames.append(tr("Speed (nm)"));
    columnNames.append(tr("Height (ft)"));

    QHeaderView *headerView = new QHeaderView(Qt::Horizontal);
    headerView->setResizeMode(QHeaderView::Stretch);

    routePointTable = new QTableWidget();
    routePointTable->setColumnCount(4);
    routePointTable->setHorizontalHeaderLabels(columnNames);
    routePointTable->setHorizontalHeader(headerView);
    routePointTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(routePointTable, SIGNAL(cellChanged(int, int)), this, SLOT(routePointTableCellChanged(int, int)));
    baseLayout->addWidget(routePointTable);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    baseLayout->addLayout(buttonLayout);
    buttonLayout->setAlignment(Qt::AlignRight);

    QPushButton *removeRoutePointButton = new QPushButton(tr("-"));
    connect(removeRoutePointButton, SIGNAL(clicked()), this, SLOT(removeRoutePointButtonClicked()));
    buttonLayout->addWidget(removeRoutePointButton);

    QPushButton *addRoutePointButton = new QPushButton(tr("+"));
    connect(addRoutePointButton, SIGNAL(clicked()), this, SLOT(addRoutePointButtonClicked()));
    buttonLayout->addWidget(addRoutePointButton);

    return baseLayout;
}

void AirTrafficManagementDialog::addRoutePointButtonClicked() {
    int index = routePointTable->rowCount();
    routePointTable->insertRow(index);
    addRoutePoint(index);
}

void AirTrafficManagementDialog::removeRoutePointButtonClicked() {
    int index = routePointTable->rowCount();
    routePointTable->removeRow(index);
    removeRoutePoint(index);
}

void AirTrafficManagementDialog::routePointTableCellChanged(int row, int column) {
    switch (column) {
        case 0:
            setTrafficLatitude(row, getLatitude(row));
            break;
        case 1:
            setTrafficLongitude(row, getLongitude(row));
            break;
        case 2:
            setTrafficSpeed(row, getSpeed(row));
            break;
        case 3:
            setTrafficHeight(row, getHeight(row));
            break;
    }
}

double AirTrafficManagementDialog::getHeight(int row) const {
    return getDoubleValueFromTable(row, 3);
}

double AirTrafficManagementDialog::getSpeed(int row) const {
    return getDoubleValueFromTable(row, 2);
}

double AirTrafficManagementDialog::getLongitude(int row) const {
    return getDoubleValueFromTable(row, 1);
}

double AirTrafficManagementDialog::getLatitude(int row) const {
    return getDoubleValueFromTable(row, 0);
}

double AirTrafficManagementDialog::getDoubleValueFromTable(int row, int column) const {
    QTableWidgetItem *item = routePointTable->item(row, column);
    QString text = item->text();
    if (text.isEmpty()) {
        return std::numeric_limits<double>::quiet_NaN();
    }
    return text.toDouble();
}

void AirTrafficManagementDialog::nameTextEdited(const QString &name) {
    setTrafficName(name);
}

void AirTrafficManagementDialog::config() {
    setWindowTitle(tr("Traffic Management"));
    setMinimumSize(600, 400);
}

AirTrafficManagementDialog::~AirTrafficManagementDialog() {
// sem implemetacao.
}

} /* namespace display */
} /* namespace ats */
