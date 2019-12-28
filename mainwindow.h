#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../abpa_tokenizer/StellarQtSDK/src/account.h"
#include "../abpa_tokenizer/StellarQtSDK/src/server.h"
#include "networkinformation.h"
#include "sourceaccount.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_accountInfo_clicked();

    void on_TestNetButton_clicked();

    void on_LiveNetButton_clicked();

    void accountResponseShow(AccountResponse *accountResponse);

    void on_pushButton_3_clicked();

    void on_createaccount_clicked();

    void on_createAccount_clicked();

    void setCreateAccKeyState();

    void doOpenAccount();

private:
    Ui::MainWindow *ui;
    NetWorkInformation kuknosNetConfig;
    sourceAccount m_srcAccount;
};
#endif // MAINWINDOW_H
