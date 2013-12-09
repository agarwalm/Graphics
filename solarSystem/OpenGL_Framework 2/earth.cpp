#include "earth.h"
#include "Base.h"
#include "Sphere.h"
#include "Sun.h"
#include "Moon.h"

Earth::Earth()
{
    QImage img;
    if(!img.load("/Users/mrigyaagarwal/Desktop/third_year/graphics/Graphics/solarSystem/OpenGL_Framework 2/earth.bmp")) {
        qWarning("ERROR LOADING IMAGE");
    }
    img.save("/Users/mrigyaagarwal/Desktop/third_year/graphics/Graphics/solarSystem/OpenGL_Framework 2/asdasd2.bmp");

    img = QGLWidget::convertToGLFormat(img);
    glGenTextures(1, &name);
    glBindTexture(GL_TEXTURE_2D, name);

    glTexImage2D(GL_TEXTURE_2D,0, GL_RGBA, img.width(), img.height(), 0,GL_RGBA, GL_UNSIGNED_BYTE,img.bits());
    //cout<< "i am bit" << img.height() << endl;
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glGenerateMipmap(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, name);
}



//void Earth::draw(double tau){
void Earth::draw(float HourOfDay, float DayOfYear){
    //draw the earth
    glRotated(360.0*DayOfYear/365.0, 0.0, 1.0, 0.0); //rotation around the sun
    glTranslated(4.0, 0.0, 0.0);

    glPushMatrix();
//(sin(23.0*PI/180)
    glRotated(360.0*HourOfDay/24.0, 0.0, 1, 0.0 ); //rotation on its own axis
    glScaled(0.5,0.5,0.5);
    glColor3f(0.2, 0.2, 1.0);

    sphere.draw();
     glDisable(GL_TEXTURE_2D);

    glPopMatrix();
Moon moon;
    //draw the children
    moon.draw(HourOfDay, DayOfYear);
}
