#include <limits>
#include <string>
#include <vector>

#include <qboxlayout.h>
#include <qgridlayout.h>
#include <qheaderview.h>
#include <qheaderview.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qmessagebox.h>
#include <qpushbutton.h>
#include <qsizepolicy.h>

#include "airtrafficdialog.h"
#include "airtrafficcontroller.h"

namespace ats {
namespace display {

using namespace std;

AirTrafficDialog::AirTrafficDialog(QWidget *parent)
        : QDialog(parent), nameLineEdit(0), routePointTable(0) {
    config();
    buildLayout();
}

void AirTrafficDialog::buildLayout() {
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(createTrafficDetailLayout());
    mainLayout->addLayout(createButtonsLayout());

    setLayout(mainLayout);
}
QLayout *AirTrafficDialog::createButtonsLayout() {
    QHBoxLayout *layout = new QHBoxLayout();
    layout->setAlignment(Qt::AlignRight);

    QPushButton *saveButton = new QPushButton(tr("Save"));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveButtonCliecked()));
    layout->addWidget(saveButton);

    return layout;
}

void AirTrafficDialog::saveButtonCliecked() {
    if (isValidTraffic()) {
        saveTraffic();

        QMessageBox::information(this, tr("Traffic"), tr("Traffic save at simulation."));
    }
    else {
        QMessageBox::warning(this, tr("Traffic"), tr("Error at new traffic."));
    }
}

QLayout *AirTrafficDialog::createTrafficDetailLayout() {
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
    columnNames.append(tr("Speed (kt)"));
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

void AirTrafficDialog::addRoutePointButtonClicked() {
    int index = routePointTable->rowCount();
    routePointTable->insertRow(index);
    addRoutePoint(index);
}

void AirTrafficDialog::removeRoutePointButtonClicked() {
    int index = routePointTable->rowCount();
    routePointTable->removeRow(index);
    removeRoutePoint(index);
}

void AirTrafficDialog::routePointTableCellChanged(int row, int column) {
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

double AirTrafficDialog::getHeight(int row) const {
    return getDoubleValueFromTable(row, 3);
}

double AirTrafficDialog::getSpeed(int row) const {
    return getDoubleValueFromTable(row, 2);
}

double AirTrafficDialog::getLongitude(int row) const {
    return getDoubleValueFromTable(row, 1);
}

double AirTrafficDialog::getLatitude(int row) const {
    return getDoubleValueFromTable(row, 0);
}

double AirTrafficDialog::getDoubleValueFromTable(int row, int column) const {
    QTableWidgetItem *item = routePointTable->item(row, column);
    QString text = item->text();
    if (text.isEmpty()) {
        return std::numeric_limits<double>::quiet_NaN();
    }
    return text.toDouble();
}

void AirTrafficDialog::nameTextEdited(const QString &name) {
    setTrafficName(name);
}

void AirTrafficDialog::config() {
    setWindowTitle(tr("Traffic"));
    setMinimumSize(600, 400);
}

AirTrafficDialog::~AirTrafficDialog() {
// sem implemetacao.
}

} /* namespace display */
} /* namespace ats */
