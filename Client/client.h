#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QTcpSocket>
#include <QVBoxLayout>

class Client : public QDialog
{
	Q_OBJECT
	
	public:
		Client(QWidget* parent = 0);
		
	private:
		QTcpSocket* socket;
		QLabel* label;
		QPushButton* button;
		QVBoxLayout* mainLayout;
		
	private slots:
		void updateLabel();
		void requestGreeting();
};

#endif
