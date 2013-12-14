#ifndef SKYBOX_H
#define SKYBOX_H
#include "cube.h"
#include <iostream>
#include <QtOpenGL>
#include <QGLWidget>
#include <QTimer>
#include <QString>
#include <QImage>
#include "Base.h"

class Skybox
{
public:
    Skybox();
    void draw();
    cube box;
    GLuint name;
    double tau;
};

#endif // SKYBOX_H
