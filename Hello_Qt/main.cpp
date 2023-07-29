#include <QApplication>
#include <QLabel>

int main(int argc , char* argv [])
{

	QApplication app (argc , argv );
	QLabel * label  = new QLabel ("Hello Shindy ");
	label->setWindowTitle("Application 1 ");
	label->resize(400,200);
	label -> show();
	return app.exec();
}
