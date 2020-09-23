#include "client.h"
#include <QtNetwork>

Client::Client(QWidget* parent) : QDialog(parent)
{
	mainLayout = new QVBoxLayout(this);
	label = new QLabel("*** Ready ***");
	button = new QPushButton("Greet Me");
	mainLayout->addWidget(label);
	mainLayout->addStretch();
	mainLayout->addWidget(button);
	
	connect(button, SIGNAL(clicked()), this, SLOT(requestGreeting()));
}

void Client::requestGreeting()
{
	socket = new QTcpSocket(this);
	connect(socket, SIGNAL(readyRead()), this, SLOT(updateLabel()));
	connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
	
	socket->connectToHost(QHostAddress::LocalHost, 1234);
}

void Client::updateLabel()
{
	QDataStream incomingMessage(socket);
	incomingMessage.setVersion(QDataStream::Qt_4_1);
	
	QString msg;
	incomingMessage >> msg;
	label->setText(msg);
	
	delete socket;
}
