
#include <QApplication>
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QGroupBox>
#include <QPushButton>
#include <QDialogButtonBox>





int main( int argc, char **argv )
{
  QApplication app( argc, argv );

  QDialog dlg;
  QGroupBox *groupBox = new QGroupBox( "Groupbox" ); // group box
  QLabel *label = new QLabel( "Supercalifragilisticexpialidocious" ); // label
  QLineEdit *lineEdit = new QLineEdit; //
  QDialogButtonBox *buttons = new QDialogButtonBox( QDialogButtonBox::Ok |QDialogButtonBox::Cancel );
  QHBoxLayout *hLayout = new QHBoxLayout( groupBox );
  hLayout->addWidget( label );
  hLayout->addWidget( lineEdit );
  QVBoxLayout *vLayout = new QVBoxLayout( &dlg );
  vLayout->addWidget( groupBox );
  vLayout->addStretch();
  vLayout->addWidget( buttons );
  dlg.show();

  return app.exec();
}
