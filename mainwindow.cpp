/**
 * @authors Yoan Laurain ; Hugo Carricart ; Nathan Lesourd
 * @brief Source Code de MainWindow
 * @file mainwindow.cpp
 * @date 26/10/2021
 * @version 0.5
 */

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Echiquier.h"
#include "Piece.h"
#include "Joueur.h"
#include <iostream>
#include <assert.h>

#include "mainwindow.h"

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QString>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    assert( jn.placerPieces( e ) );
    assert( jb.placerPieces( e ) );


    this->RefreshMatrice(this);
}

MainWindow::~MainWindow() { delete ui; }

void
MainWindow::RefreshMatrice(QWidget *parent)
{
    model = new QStandardItemModel(8,8,parent) ;

    for ( int i = 0 ; i < 8 ; i++ )
    {
        for ( int j = 0 ; j < 8 ; j++ )
        {
            if (e.getPiece(j+1, i+1) != nullptr){
               string s = e.getPiece(j+1, i+1)->path();
               int n = s.length();
               char char_array[n + 1];
               strcpy(char_array, s.c_str());
               QPixmap monImage(char_array);
               QIcon* m_icon = new QIcon();
                m_icon->addPixmap(monImage);
               QStandardItem *m_item = new QStandardItem();
                m_item->setIcon(*m_icon);

               model->setItem(i, j , m_item);
            }
       }
    }
    ui->tableViewEchiquier->setModel(model);
}


void MainWindow::on_tableViewEchiquier_clicked(const QModelIndex &index)
{

    if ( pieceEnCours != nullptr && pieceEnCours->isWhite() == WhitePlay && pieceEnCours->mouvementValide( e, index.column()+1  , index.row()+1  )  )
    {
        e.deplacer( pieceEnCours , index.column()+1  , index.row()+1 );
        WhitePlay = !WhitePlay;
        this->RefreshMatrice(this);
    }
    else
    {
        pieceEnCours = e.getPiece(  index.column()+1  , index.row()+1 );
        this->RefreshMatrice(this);
        if ( pieceEnCours != nullptr )
        {
           this->setColor( pieceEnCours->AfficheMouvementValide(e,WhitePlay) );
        }
    }  
}

void MainWindow::setColor(list<string>values)
{
   for (string coordonees : values)
   {
       std::stringstream test(coordonees);
       std::string segment;
       std::vector<std::string> seglist;

       while(std::getline(test, segment, '-'))
       {
          seglist.push_back( segment );
       }


       QModelIndex index = model->index( std::stoi( seglist.at(1) ) , std::stoi( seglist.at(0) ) ,QModelIndex());
       model->setData(index, QBrush ( QColor( Qt::blue ) ), Qt::BackgroundRole  );
       cout << "loop" << endl;
   }

   ui->tableViewEchiquier->setModel(model);
}


