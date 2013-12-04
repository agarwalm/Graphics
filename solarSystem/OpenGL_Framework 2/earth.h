#ifndef EARTH_H
#define EARTH_H
#include "planet.h"
#include <iostream>
#include <QtOpenGL>
#include <QGLWidget>
#include <QTimer>
#include <QString>
#include <QImage>
#include "Base.h"

class Earth : Planet
{
public:
    Earth();
    void draw(double);
};

#endif // EARTH_H
