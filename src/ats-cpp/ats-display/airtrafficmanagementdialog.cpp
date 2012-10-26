#include <qboxlayout.h>
#include <qcombobox.h>
#include <qgridlayout.h>
#include <qgroupbox.h>
#include <qheaderview.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qsizepolicy.h>
#include <string>
#include <vector>

#include "airtrafficmanagementdialog.hpp"
#include "airtrafficmanagementcontroller.hpp"

namespace ats {
namespace display {

using namespace std;

AirTrafficManagementDialog::AirTrafficManagementDialog(QWidget *parent, AirTrafficManagementController *controller)
        : QDialog(parent), controller(controller), detailGroupBox(0), identificationLineText(0) {
    config();
    createLayout();

    loadTrafficComboBox();
}

void AirTrafficManagementDialog::addRoutePoint() {
    routeTable->insertRow(0);
}

void AirTrafficManagementDialog::removeRoutePoint() {
    routeTable->removeRow(0);
}

void AirTrafficManagementDialog::loadTrafficComboBox() {
    trafficComboBox->addItem(tr("New Traffic"));

    vector<string> *trafficIds = controller->getTrafficIds();

    vector<string>::iterator iterator = trafficIds->begin();
    while (iterator != trafficIds->end()) {
        string trafficId = *iterator;
        trafficComboBox->addItem(QString(trafficId.c_str()));
    }

    delete trafficIds;
}

void AirTrafficManagementDialog::config() {
    setWindowTitle(tr("Air Traffic Management"));
    setMinimumSize(400, 400);
}

void AirTrafficManagementDialog::createLayout() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    setLayout(mainLayout);

    createSelectTrafficGroupBox();
    createTrafficDetailGroupBox();

    createButtons();
}

void AirTrafficManagementDialog::createButtons() {
    QFrame *frame = new QFrame();

    QHBoxLayout *hboxLayout = new QHBoxLayout(this);
    hboxLayout->addStretch();
    frame->setLayout(hboxLayout);

    saveButton = new QPushButton(tr("Save"));
    hboxLayout->addWidget(saveButton);

    QLayout *mainLayout = layout();
    mainLayout->addWidget(frame);
}

void AirTrafficManagementDialog::createTrafficDetailGroupBox() {
    QGridLayout* gridlayout = new QGridLayout();

    detailGroupBox = new QGroupBox(this);
    detailGroupBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    detailGroupBox->setLayout(gridlayout);

    QLabel *identificationLabel = new QLabel(tr("Identification"));
    gridlayout->addWidget(identificationLabel, 0, 0);

    identificationLineText = new QLineEdit();
    gridlayout->addWidget(identificationLineText, 0, 1, 1, 2);

    QStringList columnsName;
    columnsName.append(tr("X"));
    columnsName.append(tr("Y"));
    columnsName.append(tr("height"));
    columnsName.append(tr("speed"));

    QHeaderView *headerView = new QHeaderView(Qt::Horizontal);
    headerView->setResizeMode(QHeaderView::Stretch);

    routeTable = new QTableWidget(this);
    routeTable->setColumnCount(4);
    routeTable->setRowCount(2);
    routeTable->setHorizontalHeaderLabels(columnsName);
    routeTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    routeTable->setHorizontalHeader(headerView);
    gridlayout->addWidget(routeTable, 1, 0, 1, 3);

    addRoutePointButton = new QPushButton(tr("+"));
    connect(addRoutePointButton, SIGNAL(pressed()), this, SLOT(addRoutePoint()));
    gridlayout->addWidget(addRoutePointButton, 2, 1);

    removeRoutePointButton = new QPushButton(tr("-"));
    connect(removeRoutePointButton, SIGNAL(pressed()), this, SLOT(removeRoutePoint()));
    gridlayout->addWidget(removeRoutePointButton, 2, 2);

    QLayout
    *mainLayout = layout();
    mainLayout->addWidget(detailGroupBox);
}

void AirTrafficManagementDialog::createSelectTrafficGroupBox() {
    QGridLayout* gridLayout = new QGridLayout();

    QGroupBox* groupBox = new QGroupBox(tr("Select Traffic"), this);
    groupBox->setLayout(gridLayout);

    QLabel* selectionLabel = new QLabel(tr("Select"));
    gridLayout->addWidget(selectionLabel, 0, 0);

    trafficComboBox = new QComboBox();
    trafficComboBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    gridLayout->addWidget(trafficComboBox, 0, 1, 1, 2);
    connect(trafficComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(updateDetail(QString)));

    QLayout *mainLayout = layout();
    mainLayout->addWidget(groupBox);
}

void AirTrafficManagementDialog::updateDetail(QString selectedId) {
    detailGroupBox->setTitle(tr("Traffic - ") + selectedId);
}

AirTrafficManagementDialog::~AirTrafficManagementDialog() {
    delete controller;
}

} /* namespace display */
} /* namespace ats */
