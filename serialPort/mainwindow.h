#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QDebug>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_pushButton_send_clicked();

	void on_pushButton_clicked();
	void Read_Data();

private:
	Ui::MainWindow *ui;
	QSerialPort* ttyACMx_port;
	QString rxData;
	bool rxFlag = false;
};

#endif // MAINWINDOW_H
