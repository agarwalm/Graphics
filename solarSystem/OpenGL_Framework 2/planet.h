#ifndef PLANET_H
#define PLANET_H
#include "Sphere.h"
#include "CCanvas.h"
#include <iostream>
#include <QtOpenGL>
#include <QGLWidget>
#include <QTimer>
#include <QString>
#include <QImage>
#include "Base.h"




class Planet
{
public:
    Planet();
    void draw();
    std::vector< Planet > children;

    int childcount;
    Sphere sphere;



};

#endif // PLANET_H
