#include <QApplication>
#include "client.h"

int main(int argc, char* argv[])
{
	QApplication myApp(argc, argv);
	
	Client c;
	c.show();
	
	return myApp.exec();
}
