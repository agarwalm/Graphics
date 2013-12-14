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
    ccanvas->passSlider(slider);
    pauseButton = this->pushButton;



    
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





    //ccanvas->setDay(position/30+1)
}

//day box
void GLRender::on_spinBox_valueChanged(int arg1)
{



    if (sliderChange == false){

        setSlider(arg1);
    }




}


//month box
void GLRender::on_spinBox2_valueChanged(int arg1)
{

    if (sliderChange == false){

        setSlider(spinnerDay->value());
    }



}

//this method is empty but do not get rid of it or there will be an error.
void GLRender::on_horizontalSlider_valueChanged(int value)
{


    sliderChange = true;

    setSpinners(value);

    canvas->setDate(value);
    sliderChange = false;
}



void GLRender::on_pushButton_clicked()
{
    canvas->pause();
    if (pauseButton->text() == "PAUSE"){
        pauseButton->setText("PLAY");
    }
    else{
        pauseButton->setText("PAUSE");
    }

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

void GLRender::on_calendar_clicked(const QDate &date)
{

    }


void GLRender::setSlider(int day){

int month = spinnerMonth->value();

int num1 = 31;
int num2 = 30;

if (month ==1){
    slider->setValue(day);
}
else if (month == 2){
    slider->setValue(num1+day);
}
else if (month == 3){
    slider->setValue(num1+28+day);
}
else if (month == 4){
    slider->setValue(num1*2+28+day);
}
else if (month == 5){
    slider->setValue(num1*2+28+num2+day);
}
else if (month == 6){
    slider->setValue(num1*3+28+num2+day);

}
else if (month == 7){
    slider->setValue(num1*3+28+num2*2+day);

}
else if (month == 8){
    slider->setValue(num1*4+28+num2*2+day);

}
else if (month == 9){
    slider->setValue(num1*5+28+num2*2+day);

}
else if (month == 10){
    slider->setValue(num1*5+28+num2*3+day);

}
else if (month == 11){
    slider->setValue(num1*6+28+num2*3+day);

}
else if (month == 12){
    slider->setValue(num1*6+28+num2*4+day);

}
}

void GLRender:: setSpinners(int day){

    if (day<=31){

        spinnerDay->setValue(day);
        spinnerMonth->setValue(1);
    }

    else if (day <= 59 & day>31){

        spinnerDay->setValue(day-31);
        spinnerMonth->setValue(2);
    }

    else if (day <= 90 & day>59){

        spinnerDay->setValue(day-59);
        spinnerMonth->setValue(3);
    }
    else if (day <= 120 & day>90){

        spinnerDay->setValue(day-90);
        spinnerMonth->setValue(4);
    }
    else if (day <= 151 & day>120){

        spinnerDay->setValue(day-120);
        spinnerMonth->setValue(5);
    }
    else if (day <= 181 & day>151){

        spinnerDay->setValue(day-151);
        spinnerMonth->setValue(6);
    }
    else if (day <= 212 & day>181){

        spinnerDay->setValue(day-181);
        spinnerMonth->setValue(7);
    }
    else if (day <= 243 & day>212){

        spinnerDay->setValue(day-212);
        spinnerMonth->setValue(8);
    }
    else if (day <= 273 & day>243){

        spinnerDay->setValue(day-243);
        spinnerMonth->setValue(9);
    }
    else if (day <= 304 & day>273){

        spinnerDay->setValue(day-273);
        spinnerMonth->setValue(10);
    }
    else if (day <= 334 & day>304){

        spinnerDay->setValue(day-304);
        spinnerMonth->setValue(11);
    }
    else if (day <= 365 & day>334){

        spinnerDay->setValue(day-334);
        spinnerMonth->setValue(12);
    }



}











