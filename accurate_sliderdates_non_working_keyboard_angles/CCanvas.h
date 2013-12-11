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

using namespace std;

class Sun; //forward declaration

/************************************************************************/
/* Canvas to draw                                                       */
/************************************************************************/
class CCanvas : public QGLWidget
{
  Q_OBJECT

public:

    explicit CCanvas(QWidget *parent = 0) : QGLWidget(parent), sun(NULL)
  {       
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(10);
  }
    void setDate(int);
    void pause();
    void upArrow();
    void downArrow();
    void rightArrow();
    void leftArrow();
    void forward();
    void back();
      //double tau;
    float HourOfDay;
    float DayOfYear;
    float AnimateIncrement;
    int numOfDays;

    Sun *sun;


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
  Point3d eye;
  Point3d center;
  Point3d up;
  double angle;
  double angle2;


  //double tau2;

};
#endif 
