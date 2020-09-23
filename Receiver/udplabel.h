// udplabel.h - Reciever

#ifndef UDPLABEL_H
#define UDPLABEL_H

#include <QLabel>
#include <QUdpSocket>

class UDPLabel : public QLabel
{
	Q_OBJECT;
	
	public:
		UDPLabel(QString msg);
		
	private:
		QUdpSocket *myUDPSocket;
		
	private slots:
		void processPendingDatagrams();
};

#endif
