#include "Sun.h"
#include "earth.h"
#include "moon.h"
#include "Base.h"
#include "Sphere.h"
#include <QImage>




//create the children
//Earth earth;


Sun::Sun()
    :Planet()
{

    children.push_back(new Earth());
//    children.insert(children.end(), (Planet)moon);
//texture
    QImage img("./sun.bmp");
   // cout<< img << endl;
    img = QGLWidget::convertToGLFormat(img);
    glGenTextures(1, &name);
    glBindTexture(GL_TEXTURE_2D, name);
    glTexImage2D(GL_TEXTURE_2D,0, GL_RGBA, img.width(), img.height(), 0,GL_RGBA, GL_UNSIGNED_BYTE,img.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, name);
    glDisable(GL_TEXTURE_2D);

}

//void Sun::draw(double tau){

void Sun::draw(float HourOfDay, float DayOfYear){
    glPushMatrix();

    glTranslated (0.0, 0.0, -5.0);

    glPushMatrix();

    glScaled (2.0, 2.0, 2.0);
    glColor3f(1.0, 1.0, 0.0);

    sphere.draw();

    glPopMatrix();

    for (int i = 0; i < children.size(); i++){
        children[i]->draw(HourOfDay, DayOfYear);
    }

//    earth.draw(HourOfDay, DayOfYear);

}
