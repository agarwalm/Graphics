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

class Sun : Planet
{
public:
    Sun();
    void draw(double);

};

#endif // SUN_H
