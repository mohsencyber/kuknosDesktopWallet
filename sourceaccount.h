#ifndef SOURCEACCOUNT_H
#define SOURCEACCOUNT_H
#include <QString>
#include <list>
#include <QList>

class sourceAccount
{
private:
    QString m_accountID;
    QList<QString> m_privateList;
public:
    sourceAccount();
    void setAccountID(QString accountID);
    QString getAccountID();
    void setSecretList(QList<QString> secretKeyList);
    void addPrivateKey(QString privateKey);
    QList<QString> getPrivateList();

};

#endif // SOURCEACCOUNT_H
