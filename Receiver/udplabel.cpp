// udplabel.cpp -- Receiver

#include <QtGui>
#include "udplabel.h"
#include <QString>
#include <QByteArray>
#include <QDataStream>
#include <QtDebug>

UDPLabel::UDPLabel(QString msg) : QLabel(msg)
{
	myUDPSocket = new QUdpSocket(this);
	
	myUDPSocket->bind(5678);
	
	connect(myUDPSocket, SIGNAL(readyRead()),
			this, SLOT(processPendingDatagrams()));
}

void UDPLabel::processPendingDatagrams()
{
	QByteArray mydatagram;
	
	while (myUDPSocket->hasPendingDatagrams())
	{
		mydatagram.resize(myUDPSocket->pendingDatagramSize());
		myUDPSocket->readDatagram(mydatagram.data(), mydatagram.size());
	}
	
	QString msg;
	QDataStream in(&mydatagram, QIODevice::ReadOnly);
	
	in.setVersion(QDataStream::Qt_4_4); // Only necessary with QDataStream
	
	in >> msg;
	this->setText(msg);
	
}
