#include "networkinformation.h"

NetWorkInformation::NetWorkInformation()
{
    horizonIP_Port="srv2.tosan-kuknos.com:27202";
    netPassPhrase = "Kuknos-NET";
}

NetWorkInformation::NetWorkInformation(QString horizonIpPort, QString Network_id)
{
    horizonIP_Port = horizonIpPort;
    netPassPhrase = Network_id;
}


QString NetWorkInformation::getNetworkID()
{
    return netPassPhrase;
}

void NetWorkInformation::setNetworkID(QString &networkID)
{
    netPassPhrase=networkID;
}

void NetWorkInformation::setHorizonIpPort(QString &horizonIpPort)
{
    horizonIP_Port = horizonIpPort;
}

void NetWorkInformation::setFederationDB(QString &federationDB)
{
    federationDBIP_Port=federationDB;
}

QString NetWorkInformation::getHorizonIpPort()
{
    return horizonIP_Port;
}

QString NetWorkInformation::getFederationDB()
{
    return federationDBIP_Port;
}
