# Qt projects & notes 


qmake file used to build the project
```makefile
QT += core gui
greaterThan(QT_MAJOR_VERSION,4 ) : QT += widgets

SOURCES += \
    main.cpp
```


*main.cpp*
```cpp
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
```

