//#include "sh_mainwindow.h"
//#include "ui_sh_mainwindow.h"

//Sh_MainWindow::Sh_MainWindow(QWidget *parent) :
//	QMainWindow(parent),
//	ui(new Ui::Sh_MainWindow)
//{
//	ui->setupUi(this);
//}

//Sh_MainWindow::~Sh_MainWindow()
//{
//	delete ui;
//}

#include <QShortcut>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QGuiApplication>
#include <QSaveFile>
#include "sh_mainwindow.h"

#include <QShortcut>

Window::Window(QWidget * parent)
	: QMainWindow(parent) ,font_size(100)
{
	setWindowTitle("TextEditor");
	setGeometry(250, 250, 800, 600);


	textarea = new QPlainTextEdit();
	setCentralWidget(textarea);
	/*Init program tools and menus*/
	init_menubar();
	init_statusbar();
	init_toolbar();

	QFont font;
	font.setFamily("Courier");
	textarea->setFont(font);
	textarea->zoomIn(font_size);

	connect(NewAction, &QAction::triggered, this, &Window::New);
	connect(OpenAction, &QAction::triggered, this, &Window::Open);
	connect(SaveAction, &QAction::triggered, this, &Window::Save);
	connect(SaveAsAction, &QAction::triggered, this, &Window::SaveAs);
	connect(textarea->document(), &QTextDocument::contentsChanged, this, &Window::documntModified);
	setCurrentFile(QString());

}

Window::~Window()
{

}


void Window::init_menubar()
{
	filemenu = menuBar()->addMenu("File");
	{
		NewAction = new QAction(QIcon("./home/ahmedshindy/qt_workspace/TextEditor/icons/new.png"), "New");
		NewAction->setShortcut(QKeySequence::New);
		NewAction->setStatusTip("Create new File");
		filemenu->addAction(NewAction);

		OpenAction = new QAction(QIcon(":/icons/open.png"), "Open");
		OpenAction->setShortcut(QKeySequence::Open);
		OpenAction->setStatusTip("open exist File");
		filemenu->addAction(OpenAction);


		SaveAction = new QAction(QIcon(":/icons/save.png"), "Save");
		SaveAction->setShortcut(QKeySequence::Save);
		SaveAction->setStatusTip("save File");
		filemenu->addAction(SaveAction);

		SaveAsAction = new QAction(QIcon(":/icons/save_as.png"), "Save As");
		//SaveAsAction->setShortcut(QKeySequence::SaveAs); not working
		SaveAsAction->setShortcut(tr("Ctrl+Shift+S"));
		SaveAsAction->setStatusTip("save file as new format");
		filemenu->addAction(SaveAsAction);

		filemenu->addSeparator();
		ExitAction = new QAction(QIcon(":/icons/exit.png"), "Exit");
		ExitAction->setShortcut(tr("Ctrl+Q"));
		ExitAction->setStatusTip("exit program");
		filemenu->addAction(ExitAction);
	}

	helpmenu = menuBar()->addMenu("Help");
	{
		AboutAction = new QAction(QIcon(":/icons/about.png"), "help");
		AboutAction->setStatusTip("about us");
		helpmenu->addAction(AboutAction);
	}
}
void Window::documntModified()
{
	setWindowModified(textarea->document()->isModified());
}
void Window::init_toolbar()
{
	// Create toolbar
	toolbar = new QToolBar(); // use smart ptrs 


	// add actions to the toolbar
	toolbar->addAction(QIcon(), "New");
	toolbar->addAction(QIcon(), "Open");
	toolbar->addAction(QIcon(), "Save");
	toolbar->addAction(QIcon(), "Save As");
	toolbar->addAction(QIcon(), "Print");
	toolbar->addAction(QIcon(), "Copy");
	toolbar->addAction(QIcon(), "Cut");
	toolbar->addAction(QIcon(), "Paste");

	// show toolbar on your window
	addToolBar(toolbar);

}

void Window::init_statusbar()
{
	statusBar()->addPermanentWidget(new QLabel(""));
	/* we have done this befor*/
	statusBar()->addPermanentWidget(new QLabel(tr("%1 %").arg(font_size)));

}

void Window::setCurrentFile(QString filename)
{
	CurrentFilename = filename;
	textarea->document()->setModified(false);

	setWindowModified(false);

	QString showname = CurrentFilename;

	if (CurrentFilename.isEmpty())
		showname = "untitled.txt";

	setWindowFilePath(showname);
}


bool Window::maybesave()
{
	if (!textarea->document()->isModified())
		return true;

	auto ret = QMessageBox::warning(this, "Warning", "the document is modified \n do you want to save ? ",
		QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

	switch (ret)
	{
		case QMessageBox::Save:
			Save();
			break;
		case QMessageBox::Cancel:
			return false;
			break;
		case QMessageBox::Discard:
			break;
	default:
		break;
	}

	return true;
}


///////////////////////////////////////////////////// Functions

void Window::New()
{
	if (maybesave())
	{
		textarea->clear();
		setCurrentFile(QString());
	}
}

void Window::Open()
{
	if (maybesave())
	{
		CurrentFilename = QFileDialog::getOpenFileName(this);

		if (!CurrentFilename.isEmpty())
		{
			setCurrentFile(CurrentFilename);

			QFile file(CurrentFilename);

			if (!file.open(QFile::ReadOnly | QFile::Text))
			{
				QMessageBox::warning(this, "Warning", "erorr loading file");
			}

			QTextStream in(&file);

			QGuiApplication::setOverrideCursor(Qt::WaitCursor);
			textarea->document()->setPlainText(in.readAll());
			QGuiApplication::restoreOverrideCursor();
		}
	}
}

void Window::Save()
{
	if (CurrentFilename.isEmpty())
	{
		SaveAs();
	}
	else
	{
		QGuiApplication::setOverrideCursor(Qt::WaitCursor);

		QSaveFile file(CurrentFilename);

		if (file.open(QFile::WriteOnly | QFile::Text))
		{
			QTextStream out(&file);
			out << textarea->document()->toPlainText();

			if (!file.commit())
			{
				QMessageBox::warning(this, "warning", "error in saving file");
			}

		}
		else
		{
			QMessageBox::warning(this, "warning", "error in open file");
		}

		QGuiApplication::restoreOverrideCursor();
		setCurrentFile(CurrentFilename);
		statusBar()->showMessage("file saved", 2000);
	}
}

void Window::SaveAs()
{
	QFileDialog dialog(this);

	dialog.setWindowModality(Qt::WindowModal);
	dialog.setAcceptMode(QFileDialog::AcceptSave);

	if(dialog.exec() != QDialog::Accepted)
	{
		// erorr
	}
	else
	{
		CurrentFilename = dialog.selectedFiles().first();
		setCurrentFile(CurrentFilename);
		Save();
	}
}

void Window::Exit()
{
}