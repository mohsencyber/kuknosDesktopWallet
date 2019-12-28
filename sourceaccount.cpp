#include "sourceaccount.h"

sourceAccount::sourceAccount()
{

}

QString sourceAccount::getAccountID()
{
    return m_accountID;
}

void sourceAccount::setAccountID(QString accountID)
{
    m_accountID = accountID;
}

void sourceAccount::addPrivateKey(QString privateKey)
{
    m_privateList.append(privateKey);
}

QList<QString> sourceAccount::getPrivateList()
{
    return m_privateList;
}

void sourceAccount::setSecretList(QList<QString> secretKeyList)
{
    m_privateList = secretKeyList;
}
