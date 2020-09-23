#include <QApplication>
#include "udplabel.h"

int main(int argc, char* argv[])
{
	QApplication myapp(argc,argv);
	
	UDPLabel myUDPLabel("***Ready to Receive***");
	myUDPLabel.show();
	
	return myapp.exec();
}
