#include "mytcpsocket.h"

MyTcpSocket::MyTcpSocket(QObject *parent)
    :QObject(parent){}

void MyTcpSocket::doConnect()
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(connected()),this, SLOT(sl_connected()));
    connect(socket, SIGNAL(disconnected()),this, SLOT(sl_disconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(sl_bytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()),this, SLOT(sl_readyRead()));

    qDebug() << "Connection in process";
    socket->connectToHost(Ip_adrr,Id_port); //IP Adress, Port to be changed if needed in mytcpsocket.h
    if (!socket->waitForConnected(5000)) //5s waiting
    {
        qDebug() << "Error: " << socket->errorString();
    }
}

void MyTcpSocket::sl_connected()
{
    qDebug()<< "Connected";
    if(!(socket->waitForReadyRead()))
        qDebug()<<"No data acquired";
    socket->write(Id_code.toStdString().c_str());
    if(!(socket->waitForBytesWritten()))
        qDebug()<<"Writing error";
    if(!(socket->waitForReadyRead()))//Wait to receive ID_Valid
        qDebug()<<"No ID_Valid acquired";
    if(!(socket->waitForReadyRead()))//Wait to recieve welcome message
        qDebug()<<"No welcome message acquired";
}
void MyTcpSocket::sl_disconnected()
{
    qDebug()<< "Disconnected";
}
void MyTcpSocket::sl_bytesWritten(qint64 bytes)
{
    qDebug()<< bytes << "Bytes writting in progress";

}
void MyTcpSocket::sl_readyRead()
{
    qDebug() << "Reading in progress";
    receiveData = socket->readAll();
    qDebug() << receiveData;
}

QTcpSocket* MyTcpSocket::getSocket()
{
    return socket;
}









