#ifndef FORMCREATEACC_H
#define FORMCREATEACC_H

#include <QWidget>
#include <networkinformation.h>
#include <keypair.h>
#include "sourceaccount.h"

namespace Ui {
class FormCreateAcc;
}

class FormCreateAcc : public QWidget
{
    Q_OBJECT

public:
    explicit FormCreateAcc(sourceAccount *srcaccnt, QWidget *parent = nullptr);
    void setNetWorkConfig(NetWorkInformation &h);
    void setDestAccount(QString destAcc);
    void setSrcAccountKey(QString accountID);
    bool eventFilter(QObject *object,QEvent *event);
    ~FormCreateAcc();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_genNewSign_clicked();

    void on_srcAccountID_editingFinished();

private:
    Ui::FormCreateAcc *ui;
    NetWorkInformation kuknosConfig;
    QString destAccountID;
    sourceAccount *m_srcAccount;
};

#endif // FORMCREATEACC_H
