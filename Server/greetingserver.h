#ifndef GREETINGSERVER_H
#define GREETINGSERVER_H

#include <QTcpServer>

class GreetingServer : public QTcpServer
{
	Q_OBJECT
	
	public:
		GreetingServer(QObject* parent = 0);
		
	private:
		QString greetings[4];
		
	private slots:
		void sendGreeting();
};

#endif
