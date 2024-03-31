//#ifndef SH_MAINWINDOW_H
//#define SH_MAINWINDOW_H

//#include <QMainWindow>

//namespace Ui {
//class Sh_MainWindow;
//}

//class Sh_MainWindow : public QMainWindow
//{
//	Q_OBJECT

//public:
//	explicit Sh_MainWindow(QWidget *parent = 0);
//	~Sh_MainWindow();

//private:
//	Ui::Sh_MainWindow *ui;
//};

//#endif // SH_MAINWINDOW_H

#pragma once
#include <QMainWindow>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QTextEdit>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QPlainTextEdit>


class Window : public QMainWindow
{
public:
	Window(QWidget* parent = nullptr);
	~Window();


	void New();
	void Open();
	void Save();
	void SaveAs();
	void Exit();
	
private:


	void init_menubar();
	void init_statusbar();
	void init_toolbar();
	void setCurrentFile(QString filename);
	void documntModified();
	bool maybesave();



	int font_size;



	QMenu* filemenu;
	QMenu* editmenu;
	QMenu* formatmenu;
	QMenu* viewmenu;
	QMenu* helpmenu;
	QMenu* savemenu;


	QAction* NewAction;
	QAction* OpenAction;
	QAction* SaveAction;
	QAction* SaveAsAction;
	QAction* ExitAction;
	QAction* AboutAction;

	QString CurrentFilename;


	QPlainTextEdit* textarea;
	QToolBar* toolbar;
};
