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
    virtual void draw(float HourOfDay, float DayOfYear)=0;
    std::vector< Planet *> children;

    int childcount;
    Sphere sphere;
    GLuint name;
    GLuint name2;




};

#endif // PLANET_H
