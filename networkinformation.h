#ifndef NETWORKINFORMATION_H
#define NETWORKINFORMATION_H
#include <QString>

class NetWorkInformation
{
private:
    QString horizonIP_Port;
    QString federationDBIP_Port;
    QString netPassPhrase;
public:
    NetWorkInformation();
    NetWorkInformation(QString horizonIpPort, QString Network_id);
    void setHorizonIpPort(QString &horizonIpPort);
    void setNetworkID(QString &networkID);
    void setFederationDB(QString &federationDB);
    QString getHorizonIpPort();
    QString getNetworkID();
    QString getFederationDB();

};

#endif // NETWORKINFORMATION_H
