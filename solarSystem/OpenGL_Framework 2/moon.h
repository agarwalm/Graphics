#ifndef MOON_H
#define MOON_H
#include "planet.h"
#include "CCanvas.h"
#include "Base.h"
#include "Sphere.h"
#include "Sun.h"
#include <iostream>
#include <QtOpenGL>
#include <QGLWidget>
#include <QTimer>
#include <QString>
#include <QImage>


class Moon : Planet
{
public:
    Moon();
    void draw(double);
};

#endif // MOON_H
