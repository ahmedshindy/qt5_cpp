#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QChar>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ttyACMx_port = new QSerialPort();
	ttyACMx_port->setPortName("ttyACM1");
	ttyACMx_port->setBaudRate(QSerialPort::BaudRate::Baud9600);
	ttyACMx_port->setParity(QSerialPort::Parity::NoParity);
	ttyACMx_port->setFlowControl(QSerialPort::FlowControl::NoFlowControl);
	ttyACMx_port->setDataBits(QSerialPort::DataBits::Data8);
	ttyACMx_port->setStopBits(QSerialPort::StopBits::OneStop);
	ttyACMx_port->open(QIODevice::ReadWrite);

	if(ttyACMx_port->isOpen())
	{
		qDebug()<<"Opened ";
	}
	else
	{
		qDebug()<<"NOt Open";
		ttyACMx_port->error();
	}
	connect(ttyACMx_port,SIGNAL(readyRead()),this,SLOT(Read_Data()));

}
MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_send_clicked()
{
	if(ttyACMx_port->isOpen())
	{
		ttyACMx_port->write(ui->serialData->text().toLatin1() + char(10));
	}
}

void MainWindow::on_pushButton_clicked()
{
	if(ttyACMx_port->isOpen())
	{
		while(ttyACMx_port->bytesAvailable())
		{
			qDebug() << ttyACMx_port->readAll();
		}
	}
}

void MainWindow::Read_Data()
{
	if(ttyACMx_port->isOpen())
	{
		while(ttyACMx_port->bytesAvailable())
		{
			rxData+=ttyACMx_port->readAll();
		}
		if(rxData.at(rxData.length() -1 ) == char(10))
		{
			rxFlag = true;
		}
		if(rxFlag== true)
		{
			qDebug() << rxData;
			rxData = "";
			rxFlag= false;
		}
	}

}

