#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
//#include <Qpointer>
#include <QDebug>

class MyTcpSocket : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpSocket(QObject *parent = 0);
    QTcpSocket* getSocket();
    void doConnect();
signals:

public slots:
    void sl_connected();
    void sl_disconnected();
    void sl_bytesWritten(qint64 bytes);
    void sl_readyRead();
private:
    //QPointer<QTcpSocket> socket;
    QTcpSocket *socket;
    QString receiveData;
    const QString Id_code = "59ef-6F70-4bM7\n";
    const QString Ip_adrr = "10.33.13.7";
    const qint16 Id_port = 975;
};
#endif // MYTCPSOCKET_H
