#include "Sun.h"
#include "earth.h"
#include "moon.h"
#include "Base.h"
#include "Sphere.h"
#include <GLUT/glut.h>
#include "saturn.h"






Sun::Sun()
{
    tau = 0;
    switchTex = 0;

    glEnable(GL_TEXTURE_2D);

//    children.insert(children.end(),(Planet)earth);
//    children.insert(children.end(), (Planet)moon);

    QImage img;
    if( !img.load("/Users/christinegraff/Documents/OpenGL_Framework 2/shiftedSun.bmp")){
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

    //glEnable(GL_TEXTURE_2D);
    //glBindTexture(GL_TEXTURE_2D, name);

    QImage img2;
    if( !img2.load("/Users/christinegraff/Documents/OpenGL_Framework 2/sun.bmp")){
        qWarning("ERROR LOADING IMAGE");
    }

    //img.save("/Users/christinegraff/Documents/OpenGL_Framework 2/asdasd.bmp");

    //img.save("asd");
    //cout<< img << endl;
    img2 = QGLWidget::convertToGLFormat(img2);
    glGenTextures(1, &name2);
    glBindTexture(GL_TEXTURE_2D, name2);
    glTexImage2D(GL_TEXTURE_2D,0, GL_RGBA, img2.width(), img2.height(), 0,GL_RGBA, GL_UNSIGNED_BYTE,img2.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glGenerateMipmap(GL_TEXTURE_2D);




    //glBindTexture(GL_TEXTURE_2D, name);


//    GLenum err;
//        while ((err = glGetError()) != GL_NO_ERROR) {
//            cerr << "OpenGL error: " << err << endl;
//        }

    children.push_back(new Earth());
    children.push_back(new Saturn());
}



void Sun::draw(float HourOfDay, float DayOfYear){
    //glDisable(GL_TEXTURE_2D);
    //glColor3f(0.0, 0.0, 2.0);
    glPushMatrix();

    glTranslated (0.0, 0.0, -7.0);

    glPushMatrix();
    glRotated(90,1.0,0,0);

    glScaled (2.0, 2.0, 2.0);
    //glRotated(tau*0.3,0,0,1.0);



    if (switchTex == 0){
        glBindTexture(GL_TEXTURE_2D, name);
        if ((int)tau%50 == 0){
            switchTex = 1;
        }
    }
    else {
       glBindTexture(GL_TEXTURE_2D, name2);
       if ((int)tau%50 == 0){
           switchTex = 0;
       }
    }

//    glActiveTexture(GL_TEXTURE1);
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, name2);

//    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
//    glEnable(GL_BLEND);

//    glMatrixMode(GL_TEXTURE);
//   glRotated(0.5,0,0,1.0);
//    //glTranslated(1.0,0,0);
//    glMatrixMode(GL_MODELVIEW);

//    glMatrixMode(GL_TEXTURE1);
//    glRotated(-tau,0,0,1.0);
//    glMatrixMode(GL_MODELVIEW);
//
//    glEnable (GL_BLEND);
//    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    glDisable(GL_LIGHTING);
    sphere.draw();
    glEnable(GL_LIGHTING);
 //   glDisable(GL_BLEND);
    //box.draw(0.5);
    //glDisable(GL_TEXTURE_2D);
    glPopMatrix();

//    glDisable(GL_TEXTURE_2D);
//    glActiveTexture(GL_TEXTURE0);

    for (int i = 0; i <children.size(); i++){
        children[i]->draw(HourOfDay, DayOfYear);
    }

    glPopMatrix();

    tau +=1.0;


}
