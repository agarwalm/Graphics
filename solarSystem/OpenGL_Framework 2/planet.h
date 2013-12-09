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
    virtual void draw(float, float) = 0;
    std::vector< Planet *> children;

    int childcount;
    Sphere sphere;
    GLuint name;

//save name



};

#endif // PLANET_H
