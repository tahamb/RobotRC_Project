#include <QCoreApplication>
#include "mytcpsocket.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyTcpSocket s;
    s.doConnect();
    {
        s.getSocket()->write("<ALL>\n");
        if(!(s.getSocket()->waitForBytesWritten()))
            qDebug()<<"Error: Writing data";
        if(!(s.getSocket()->waitForReadyRead()))
            qDebug()<<"No data acquired";
        /*
        s.getSocket()->write("<CAR-POSITION>\n");
        if(!(s.getSocket()->waitForBytesWritten()))
            qDebug()<<"Error: Writing data";
        if(!(s.getSocket()->waitForReadyRead()))
            qDebug()<<"No data acquired";
        s.getSocket()->write("<car-autre>\n");
        if(!(s.getSocket()->waitForBytesWritten()))
            qDebug()<<"Error: Writing data";
        if(!(s.getSocket()->waitForReadyRead()))
            qDebug()<<"No data acquired";
        s.getSocket()->write("<STOP>");
        if(!(s.getSocket()->waitForBytesWritten()))
            qDebug()<<"No data acquired";
        if(!(s.getSocket()->waitForReadyRead()))
            qDebug()<<"No data acquired";
            */
        s.getSocket()->disconnectFromHost();
    }
    return a.exec();
}
