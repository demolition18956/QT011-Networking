#include <QApplication>
#include "senderdialog.h"

int main(int argc, char* argv[])
{
	QApplication myapp(argc,argv);
	
	SenderDialog mysender;
	mysender.show();
	
	return myapp.exec();
}
