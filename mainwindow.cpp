#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "formcreateacc.h"
#include <QEvent>
#include "../abpa_tokenizer/StellarQtSDK/src/keypair.h"
#include "../abpa_tokenizer/StellarQtSDK/src/network.h"
#include "../abpa_tokenizer/StellarQtSDK/src/server.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , kuknosNetConfig("https://hz1-test.kuknos.org/","Kuknos-NET")
    /*"https://srv2.tosan-kuknos.com:27202/"*/
{
    ui->setupUi(this);
    ui->TestNetButton->setChecked(true);
    ui->textEdit->setReadOnly(true);
    ui->createAccount->setEnabled(false);

    connect(ui->publicLine,&QLineEdit::textChanged,this,&MainWindow::setCreateAccKeyState);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    close();
}

void MainWindow::on_pushButton_2_clicked()
{
    KeyPair* accountKeyPair = KeyPair::random();
    ui->publicLine->setText(accountKeyPair->getAccountId());
    ui->privateLine->setText(accountKeyPair->getSecretSeed());
    ui->createAccount->setEnabled(true);
    //QMessageBox qmsg;
    //qmsg.setText(kuknosNetConfig.getNetworkID());
    //qmsg.exec();
}

void MainWindow::on_accountInfo_clicked()
{
    Network::use(new Network(kuknosNetConfig.getNetworkID()));
    //Network::useTestNetwork();
    Server * server = new Server(kuknosNetConfig.getHorizonIpPort());
    QString strResult=ui->publicLine->text();
    QString strKey=strResult;

    try {
        AccountResponse *accountResponse = server->accounts().account(KeyPair::fromAccountId(strResult));
        connect(accountResponse,&AccountResponse::ready,[=](){
            accountResponseShow(accountResponse);
        });
    } catch (std::exception e) {
        ui->textEdit->setPlainText("Invalid AccountID");
    }

}

void MainWindow::accountResponseShow(AccountResponse *accountResponse)
{
    if (accountResponse->accountID().isEmpty())
    {
        //account not created.
        ui->textEdit->setPlainText("\nAccount not transactions in Chain.\nYou can create this accountID");
        ui->createAccount->setEnabled(true);
        return;
    }
    int lenResult = accountResponse->getBalances().size();
    for (int i=0 ; i< lenResult; i++){
        if (accountResponse->getBalances()[i].getAssetType()=="native")
            ui->textEdit->append("PMN");
        else
            ui->textEdit->append(accountResponse->getBalances()[i].getAssetCode());
        ui->textEdit->append(accountResponse->getBalances()[i].getBalance());
    }
    ui->createAccount->setEnabled(false);

}

void MainWindow::on_TestNetButton_clicked()
{
    QString networkid="Kuknos-NET" ,horizonurl="http://srv2.tosan-kuknos.com:27202/";//"https://hz1-test.kuknos.org/";//"";
    kuknosNetConfig.setNetworkID(networkid);
    kuknosNetConfig.setHorizonIpPort(horizonurl);
}

void MainWindow::on_LiveNetButton_clicked()
{
    QString networkid="Kuknos Foundation, Feb 2019" ,horizonurl="http://srv1.tosan-kuknos.com/horizon/";
    kuknosNetConfig.setNetworkID(networkid);
    kuknosNetConfig.setHorizonIpPort(horizonurl);

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_createaccount_clicked()
{

}

void MainWindow::on_createAccount_clicked()
{
    auto *formcreater = new FormCreateAcc(&m_srcAccount);
    formcreater->setNetWorkConfig(kuknosNetConfig);
    //formcreater->setSrcAccountKey(ui->publicLine->text());

    this->installEventFilter(formcreater);
    //connect(formcreater,&FormCreateAcc::on_pushButton_2_clicked,this,&MainWindow::showSigners);
    connect(formcreater,&FormCreateAcc::signalCloseForm,this,&MainWindow::onSourceAccReady);
    formcreater->show();

    //ui->textEdit->append(m_srcAccount.getAccountID());
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if ( event->type() == QEvent::Close )
    {
        ui->textEdit->append(m_srcAccount.getAccountID());
        obj->event(event);
    }
    return true;
}

void MainWindow::onSourceAccReady(QEvent::Type evtype)
{
    if ( evtype == QEvent::Close )
    {
        ui->textEdit->append(m_srcAccount.getAccountID());
        ui->textEdit->append(QString::number(m_srcAccount.getPrivateList().length()));
    }
    //create account in network
}
void MainWindow::showSigners()
{
    ui->textEdit->append(m_srcAccount.getAccountID());
}

void MainWindow::setCreateAccKeyState()
{
    KeyPair keytest;
    if ( ui->publicLine->text().length() )
    {
        try {
            keytest.fromAccountId(ui->publicLine->text());
            ui->createAccount->setEnabled(true);
            return;
        }catch(...)
        {
            //.....
        }
    }
    ui->createAccount->setEnabled(false);
}

void MainWindow::doOpenAccount()
{
    ui->textEdit->append(m_srcAccount.getAccountID());
}
