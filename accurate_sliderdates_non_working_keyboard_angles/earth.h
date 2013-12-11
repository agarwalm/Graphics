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

class Earth : public Planet
{
public:
    Earth();
    void draw(float, float);
};

#endif // EARTH_H
