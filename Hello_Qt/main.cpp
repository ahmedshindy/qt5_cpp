/*
 * Copyright (c) 2006-2007, Johan Thelin
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright notice,
 *       this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright notice,
 *       this list of conditions and the following disclaimer in the documentation
 *       and/or other materials provided with the distribution.
 *     * Neither the name of APress nor the names of its contributors
 *       may be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <QApplication>

#include <QSplitter>

#include <QTreeView>
#include <QListView>
#include <QTableView>
#include <QString>
#include <QSerialPort>
#include <QStandardItemModel>

int main( int argc, char **argv )
{
  QApplication app( argc, argv );
  return app.exec();
}




//int main( int argc, char **argv )
//{
//  QApplication app( argc, argv );

//  QTreeView *tree = new QTreeView();
//  QListView *list = new QListView();
//  QTableView *table = new QTableView();

//  QSplitter splitter;
//  splitter.addWidget( tree );
//  splitter.addWidget( list );
//  splitter.addWidget( table );
//QStandardItemModel model( 5, 2 );
////  for( int r=0; r<5; r++ )
////	for( int c=0; c<2; c++)
////	{
////	  QStandardItem *item = new QStandardItem( QString("Row:%0, Column:%1").arg(r).arg(c) );

////	  if( c == 0 )
////		for( int i=0; i<3; i++ )
////		  item->appendRow( new QStandardItem( QString("Item %0").arg(i) ) );

////	  model.setItem(r, c, item);
////	}
//QStandardItem *myItem= new QStandardItem(Qstring());
//tree->setModel(&myItem);
////	tree->setModel( &model );
////  list->setModel( &model );
////  table->setModel( &model );

////  list->setSelectionModel( tree->selectionModel() );
////  table->setSelectionModel( tree->selectionModel() );

//  splitter.show();

//  return app.exec();
//}
