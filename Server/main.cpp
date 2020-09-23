#include <QCoreApplication>
#include <QtDebug>
#include "greetingserver.h"

int main(int argc, char* argv[])
{
	QCoreApplication myApp(argc, argv);
	
	GreetingServer server;
	qDebug() << "Server running";
	
	return myApp.exec();
}
