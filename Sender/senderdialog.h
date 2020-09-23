#ifndef SENDERDIALOG_H
#define SENDERDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QUdpSocket>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

class SenderDialog : public QDialog
{
	Q_OBJECT

	public:
		SenderDialog(QWidget *parent = 0);
	
	private:
		QLabel* label;
		QLineEdit* lineEdit;
		QPushButton* sendButton;
		QPushButton* quitButton;
		
		QVBoxLayout* mainLayout;
		QHBoxLayout* editLayout;
		QHBoxLayout* buttonLayout;
		
		QUdpSocket* sendSocket;
		
	private slots:
		void writeMessage();
};
#endif
