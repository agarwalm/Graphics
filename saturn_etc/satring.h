#ifndef SATRING_H
#define SATRING_H
#include "hollowcircle.h"
#include "planet.h"
#include <iostream>
#include <QtOpenGL>
#include <QGLWidget>
#include <QTimer>
#include <QString>
#include <QImage>
#include "Base.h"


class SatRing : public Planet
{
public:
    SatRing();
    HollowCircle myRings;
    void draw(float, float);

};

#endif // SATRING_H
