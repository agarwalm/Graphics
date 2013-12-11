/****************************************************************************
** simple image viewer using qt
****************************************************************************/

#ifndef GLRENDER_H
#define GLRENDER_H


#include "ui_GLRender.h"
#include "CCanvas.h"

class GLRender : public QMainWindow, private Ui::GLRender
{
  Q_OBJECT

public:

  GLRender(QWidget *parent = 0, Qt::WindowFlags flags = 0);
  virtual ~GLRender();
  QSlider* slider;
  QSpinBox* spinnerDay;
  QSpinBox* spinnerMonth;
  QPushButton* pauseButton;
  CCanvas *ccanvas;
  void setSlider(int);

  void setSpinners(int);

public slots:

  /************************************************************************/
  /* file operations                                                      */
  /************************************************************************/
  void loadImage();
  void saveImage();
  

private slots:
  void on_horizontalSlider_sliderMoved(int position);

  void on_spinBox_valueChanged(int arg1);

  void on_spinBox2_valueChanged(int arg1);

  void on_horizontalSlider_valueChanged(int value);

  void on_pushButton_clicked();

  void keyPressEvent(QKeyEvent* k);

  void on_calendar_clicked(const QDate &date);



private:
  void setupConnections();

  QString knownFileTypes;

};


#endif
