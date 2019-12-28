#include "formcreateacc.h"
#include "ui_formcreateacc.h"
#include <QMessageBox>
#include <QStringListModel>

FormCreateAcc::FormCreateAcc(sourceAccount *srcaccnt,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCreateAcc),
    m_srcAccount(srcaccnt)
{
    ui->setupUi(this);
    ui->comboBox->setDuplicatesEnabled(false);
    QRegExp regEx("G([A-Z0-9])\\w{54}");//"G[A-Z0-9]{54}");

   QRegExpValidator *publicValidator= new QRegExpValidator(regEx);
   ui->srcAccountID->setValidator(publicValidator);

    //ui->srcAccountID->installEventFilter(this);
}

FormCreateAcc::~FormCreateAcc()
{
    delete ui;
}

void FormCreateAcc::on_pushButton_clicked()
{

}
void FormCreateAcc::setNetWorkConfig(NetWorkInformation &h)
{
    kuknosConfig = h;
}
void FormCreateAcc::on_pushButton_2_clicked()
{
    m_srcAccount->setAccountID(ui->srcAccountID->text());
    //QStringListModel strModel;

    //ui->comboBox->setModel(&strModel);
    //m_srcAccount->setSecretList(strModel.stringList());
    close();
}

bool FormCreateAcc::eventFilter(QObject *object, QEvent *event)
{
    if ( event->type() == QEvent::FocusOut )
    {
        if ( object == ui->srcAccountID )
        {
            if (ui->srcAccountID->text().startsWith("G") && ui->srcAccountID->text().length()== 56 )
                return true;
            QMessageBox mssgBox ;
            mssgBox.setText("Error : Invalid AccountID ");
            mssgBox.addButton(QMessageBox::Ok);
            mssgBox.exec();
        }
    }
    return false;
}

void FormCreateAcc::setDestAccount(QString destAcc)
{
    destAccountID=destAcc;
}

void FormCreateAcc::setSrcAccountKey(QString accountID)
{
    ui->srcAccountID->setText(accountID);

}

void FormCreateAcc::on_genNewSign_clicked()
{
    QString newKeyInput = ui->srcAccountPrivate->text();
    if ( newKeyInput.length() == 56 && newKeyInput.startsWith("S") )
    {
        if (ui->comboBox->findText(newKeyInput)==-1)
        {
            ui->comboBox->addItem(ui->srcAccountPrivate->text());
            m_srcAccount->addPrivateKey(ui->srcAccountPrivate->text());
            ui->srcAccountPrivate->clear();
            return;
        }
        ui->srcAccountPrivate->clear();
    }
}

void FormCreateAcc::on_srcAccountID_editingFinished()
{
/*
    if (ui->srcAccountID->text().length()
            || (ui->srcAccountID->text().startsWith("G") && ui->srcAccountID->text().length()== 56 ))
        return;
    QMessageBox mssgBox ;
    mssgBox.setText("Error : Invalid AccountID ");
    mssgBox.addButton(QMessageBox::Ok);
    mssgBox.exec();
*/
}
