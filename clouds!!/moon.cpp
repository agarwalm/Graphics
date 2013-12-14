#include "moon.h"
#include "Base.h"
#include "Sphere.h"



Moon::Moon()
{

    glEnable(GL_TEXTURE_2D);
    QImage img;
    if( !img.load("/Users/christinegraff/Documents/OpenGL_Framework 2/moon.bmp")){
        qWarning("ERROR LOADING IMAGE");
    }

    //img.save("/Users/christinegraff/Documents/OpenGL_Framework 2/asdasd.bmp");

    //img.save("asd");
    //cout<< img << endl;
    img = QGLWidget::convertToGLFormat(img);
    glGenTextures(1, &name);
    glBindTexture(GL_TEXTURE_2D, name);
    glTexImage2D(GL_TEXTURE_2D,0, GL_RGBA, img.width(), img.height(), 0,GL_RGBA, GL_UNSIGNED_BYTE,img.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glGenerateMipmap(GL_TEXTURE_2D);


}

void Moon::draw(float HourOfDay, float DayOfYear){


    glRotated(360.0*12.0*DayOfYear/365.0, 0.0, 1.0, 0.0 );
    glTranslated (0.7, 0.0, 0.0 );

    glPushMatrix();

    glScaled(0.136,0.136, 0.136);
    //glColor3f(0.3, 0.7, 0.3);
    glBindTexture(GL_TEXTURE_2D, name);
    sphere.draw();

    glPopMatrix();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}
