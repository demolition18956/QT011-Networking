#include "senderdialog.h"
#include <QUdpSocket>	

SenderDialog::SenderDialog(QWidget* parent) : QDialog(parent)
{
	label = new QLabel("Enter Message Here:");
	lineEdit = new QLineEdit;
	sendButton = new QPushButton("&Send");
	quitButton = new QPushButton("&Quit");
	mainLayout = new QVBoxLayout(this);
	editLayout = new QHBoxLayout;
	buttonLayout = new QHBoxLayout;
	
	mainLayout->addLayout(editLayout);
	mainLayout->addStretch();
	mainLayout->addLayout(buttonLayout);
	editLayout->addWidget(label);
	editLayout->addWidget(lineEdit);
	buttonLayout->addStretch();
	buttonLayout->addWidget(sendButton);
	buttonLayout->addWidget(quitButton);
	
	connect(sendButton, SIGNAL(clicked()), this, SLOT(writeMessage()));
	connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
	
	sendSocket = new QUdpSocket;
}

void SenderDialog::writeMessage() 
{
	QByteArray datagram;
	
	QDataStream out(&datagram, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_4); // only necessary in QDataStream
	
	QString msg = lineEdit->text();
	lineEdit->setText("");
	
	out << msg;
	
	sendSocket->writeDatagram(datagram, QHostAddress::LocalHost, 5678);
}

