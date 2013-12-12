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


class Moon : public Planet
{
public:
    Moon();
    void draw(float, float);
};

#endif // MOON_H
