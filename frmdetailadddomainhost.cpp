#include "frmdetailadddomainhost.hpp"
#include "ui_frmdetailadddomainhost.h"

FrmDetailAddDomainHost::FrmDetailAddDomainHost(FrmDetailAddDomainHostType type, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmDetailAddDomainHost)
{
    ui->setupUi(this);
    this->setCurrentType(type);
    connect(this->ui->btnCancel,&QPushButton::clicked,this,&QMainWindow::close);
}

FrmDetailAddDomainHost::~FrmDetailAddDomainHost()
{
    delete ui;
}

FrmDetailAddDomainHostType FrmDetailAddDomainHost::getCurrentType() const
{
    return currentType;
}

void FrmDetailAddDomainHost::setCurrentType(const FrmDetailAddDomainHostType &value)
{
    currentType = value;
    switch (currentType) {
    case FrmDetailAddDomainHostType::DOMAIN:
        this->setWindowTitle(tr("FRMDETAILADD - DOMAIN"));
        this->ui->lblValue->setText(tr("ENTER DOMAINNAME"));
        break;
    case FrmDetailAddDomainHostType::HOST:
        this->setWindowTitle(tr("FRMDETAILADD - HOST"));
        this->ui->lblValue->setText(tr("ENTER HOSTNAME"));
        break;
    default:
        QMessageBox::critical(this,tr("ERROR"),tr("INVALID SELECTION - CLOSING"),QMessageBox::Ok,QMessageBox::Ok);
        QTimer::singleShot(0, this, &QMainWindow::close);
        break;
    }
}
