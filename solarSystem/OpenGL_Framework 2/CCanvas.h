/************************************************************************/
/* guards                                                               */
/************************************************************************/
#ifndef CCANVAS_H
#define CCANVAS_H

#include <iostream>
#include <QtOpenGL>
#include <QGLWidget>
#include <QTimer>
#include <QString>
#include <QImage>
#include "Base.h"
#include "Animation.h"

using namespace std;

/************************************************************************/
/* Canvas to draw                                                       */
/************************************************************************/
class CCanvas : public QGLWidget
{
  Q_OBJECT

public:

  explicit CCanvas(QWidget *parent = 0) : QGLWidget(parent)//,HourOfDay(0.0)
  {       
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(10);
  };
     // double tau;
    float HourOfDay;
   float DayOfYear;
   float AnimateIncrement;

protected:

  void initializeGL();
  void resizeGL(int width, int height);
  void paintGL();

private:
  void lookAt(const GLdouble eyex,
                              const GLdouble eyey,
                              const GLdouble eyez,
                              const GLdouble centerx,
                              const GLdouble centery,
                              const GLdouble centerz,
                              const GLdouble upx,
                              const GLdouble upy,
                              const GLdouble upz);


  void glPerspective(
          const GLdouble fovy,
          const GLdouble aspect,
          const GLdouble zNear,
          const GLdouble zFar);
  // List of vertices and triangles
  vector< Point3d > v;
  struct Triangle { int v[3]; };
  vector< Triangle > t;

  //double tau2;

};
#endif 
