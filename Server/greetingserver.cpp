#include <QtNetwork>
#include "greetingserver.h"

GreetingServer::GreetingServer(QObject* parent) : QTcpServer(parent)
{
	greetings[0] = "Hello";
	greetings[1] = "Howdy";
	greetings[2] = "Salutations";
	greetings[3] = "Aloha";
	
	// Initialize random number generator to number of seconds
	// between 00:00:00 and now
	qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
	
	// Send greeting upon new connection
	connect(this, SIGNAL(newConnection()), this, SLOT(sendGreeting()));
	
	// Listen for incoming connects on port 1234 of this machine
	this->listen(QHostAddress::LocalHost, 1234);
}

void GreetingServer::sendGreeting()
{
	// Socket created as child of GreetingServer object 
	QTcpSocket* client = this->nextPendingConnection();
	
	QByteArray block;
	QDataStream outgoingMessage(&block, QIODevice::WriteOnly);
	
	outgoingMessage.setVersion(QDataStream::Qt_4_1);
	
	// Select random greeting
	outgoingMessage << greetings[qrand() % 4];
	
	// Write greeting to socket
	client->write(block);
	
	// Attempt to close socket but wait until pending data written
	client->disconnectFromHost();
}
