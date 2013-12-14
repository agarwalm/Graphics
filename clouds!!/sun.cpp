#include "Sun.h"
#include "earth.h"
#include "moon.h"
#include "Base.h"
#include "Sphere.h"
#include <GLUT/glut.h>






Sun::Sun()
{
    tau = 0;

    glEnable(GL_TEXTURE_2D);

//    children.insert(children.end(),(Planet)earth);
//    children.insert(children.end(), (Planet)moon);

    QImage img;
    if( !img.load("/Users/christinegraff/Documents/OpenGL_Framework 2/sun.bmp")){
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



    //glBindTexture(GL_TEXTURE_2D, name);


//    GLenum err;
//        while ((err = glGetError()) != GL_NO_ERROR) {
//            cerr << "OpenGL error: " << err << endl;
//        }

    children.push_back(new Earth());
}



void Sun::draw(float HourOfDay, float DayOfYear){

    glTranslated (0.0, 0.0, -7.0);

    glPushMatrix();
    glRotated(90,1.0,0,0);

    glScaled (2.0, 2.0, 2.0);
    glRotated(tau*0.3,0,0,1.0);
    glBindTexture(GL_TEXTURE_2D, name);

//    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
//    glEnable(GL_BLEND);

    sphere.draw();
    //box.draw(0.5);
    //glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    for (int i = 0; i <children.size(); i++){
        children[i]->draw(HourOfDay, DayOfYear);
    }

    tau +=1.0;


}
