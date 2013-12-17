#include "skybox.h"
#include <GLUT/glut.h>
#include <math.h>

Skybox::Skybox()
{
    tau = 0;
    box = cube(1.0);

    glEnable(GL_TEXTURE_2D);

//    children.insert(children.end(),(Planet)earth);
//    children.insert(children.end(), (Planet)moon);

    QImage img;
    if( !img.load("/Users/christinegraff/Documents/OpenGL_Framework 2/starf.jpg")){
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

void Skybox::draw(){

    glPushMatrix();

    //glTranslated (0.0, 0.0, -0.5);

    //glPushMatrix();
    //glRotated(90,1.0,0,0);

    //glScaled (2.0, 2.0, 2.0);
    //glRotated(tau*0.3,0,0,1.0);
    glBindTexture(GL_TEXTURE_2D, name);

//    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
//    glEnable(GL_BLEND);

    glDisable(GL_DEPTH_TEST);

    box.draw(2.0);
    //cout<<box.x()<<box.y()<<box.z()<<endl;
    //glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);

    tau += 1.0;




}
