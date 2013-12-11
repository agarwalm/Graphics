/****************************************************************************
** simple image viewer using qt
****************************************************************************/

#include <QtGui>
#include "GLRender.h"
#include <iostream>
#include <QKeyEvent>
#include <QDebug>


/************************************************************************/
/* setup the UI                                                         */
/************************************************************************/
GLRender::GLRender(QWidget *parent,Qt::WindowFlags flags)
    : QMainWindow(parent, flags)
{
    setupUi(this);

    setupConnections();

    knownFileTypes = QString("Image Files ( *.jpg *.png *.bmp *.tiff )");

    slider = this->horizontalSlider;
    spinnerDay = this->spinBox;
    spinnerMonth = this->spinBox2;

    ccanvas=this->canvas;





//    QObject::connect(spinnerDay, SIGNAL(valueChanged(int)),slider, SLOT(setValue(int)));
//    QObject::connect(slider, SIGNAL(valueChanged(int)),spinnerDay, SLOT(setValue(int)));

    
}


/************************************************************************/
/*                                                                      */
/************************************************************************/
GLRender::~GLRender()
{ 
  //if (canvas) delete canvas; 
}


/************************************************************************/
/* setup connections                                                    */
/************************************************************************/
void GLRender::setupConnections() 
{
   connect( actionLoad, SIGNAL( triggered() ), this, SLOT( loadImage() ) );
   connect( actionSave, SIGNAL( triggered() ), this, SLOT( saveImage() ) );
}


/************************************************************************/
/* load an Image                                                        */
/************************************************************************/
void GLRender::loadImage()
{
  QString fname = QFileDialog::getOpenFileName( this, "Open File",
    ".", knownFileTypes );

  if( !fname.isEmpty() ) {
    ;
    //canvas->load(fname);
  }
  else
    QMessageBox::critical( this, "Error Message", "error loading file" );
}


/************************************************************************/
/*  save an Image                                                       */
/************************************************************************/
void GLRender::saveImage()
{  
 
  QString fname = QFileDialog::getSaveFileName( this, "Save File",
    ".", knownFileTypes );

  if( !fname.isEmpty() )
    ;
    //canvas->save(fname);
  else 
    QMessageBox::critical( this, "Error Message", "error saving mesh" );  
}

bool sliderChange = false;
 
void GLRender::on_horizontalSlider_sliderMoved(int position)
{

    //TODO: make this math more accurate

    sliderChange = true;
    spinnerDay->setValue(position%30);
    spinnerMonth->setValue(position/30+1);
    canvas->setDate(position);
    sliderChange = false;

    //ccanvas->setDay(position/30+1)
}

//day box
void GLRender::on_spinBox_valueChanged(int arg1)
{
    if (sliderChange == false){
    //TODO: make this math more accurate
    slider->setValue((spinnerMonth->value()-1)*30+arg1);
    canvas->setDate((spinnerMonth->value()-1)*30+arg1);

    }


}


//month box
void GLRender::on_spinBox2_valueChanged(int arg1)
{

    if (sliderChange == false){


    slider->setValue((arg1-1)*30+spinnerDay->value());
    canvas->setDate((arg1-1)*30+spinnerDay->value());
    }



}

//this method is empty but do not get rid of it or there will be an error.
void GLRender::on_horizontalSlider_valueChanged(int value)
{


}



void GLRender::on_pushButton_clicked()
{
    canvas->pause();
}


void GLRender::keyPressEvent(QKeyEvent* k){

    int key = k->key();
    //cout<<key<<endl;

    //up arrow
    if (key == Qt::Key_Up){

        canvas->upArrow();
    }
    else if (key == Qt::Key_Left){

        canvas->leftArrow();

    }
    else if (key == Qt::Key_Right){

        canvas->rightArrow();
    }
    else if (key == Qt::Key_Down ){

        canvas->downArrow();
    }
    else if (key == Qt::Key_F){

        canvas->forward();
    }
    else if (key == Qt::Key_B){

        canvas->back();
    }

}
