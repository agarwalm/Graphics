#ifndef SUN_H
#define SUN_H
#include "planet.h"
#include <iostream>
#include <QtOpenGL>
#include <QGLWidget>
#include <QTimer>
#include <QString>
#include <QImage>
#include "Base.h"

class Sun : public Planet
{
public:
    Sun();
    QImage img;
   // void draw(double);
    void draw(float, float);
};

#endif // SUN_H
