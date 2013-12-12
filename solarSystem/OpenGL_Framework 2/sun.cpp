#include "Sun.h"
#include "earth.h"
#include "moon.h"
#include "Base.h"
#include "Sphere.h"
#include <GLUT/glut.h>
#include "cube.h"





Sun::Sun()
{

//    glEnable(GL_TEXTURE_2D);


//    QImage img;
//    if( !img.load("/Users/mrigyaagarwal/Desktop/third_year/graphics/Graphics/solarSystem/OpenGL_Framework 2/sun.bmp")){
//        qWarning("ERROR LOADING IMAGE");
//    }
//    img = QGLWidget::convertToGLFormat(img);
//    glGenTextures(1, &name);
//    glBindTexture(GL_TEXTURE_2D, name);
//    glTexImage2D(GL_TEXTURE_2D,0, GL_RGBA, img.width(), img.height(), 0,GL_RGBA, GL_UNSIGNED_BYTE,img.bits());
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    glGenerateMipmap(GL_TEXTURE_2D);

    children.push_back(new Earth());
}



void Sun::draw(float HourOfDay, float DayOfYear){
    //glPushMatrix();

    glTranslated (0.0, 0.0, -7.0);

    glPushMatrix();
    glScaled (2.0, 2.0, 2.0);
//    glColor3f(1.0, 1.0, 0.0);
    //glBindTexture(GL_TEXTURE_2D, name);
    cube.draw(0.5);
   // sphere.draw();
    glPopMatrix();


    for (int i = 0; i <children.size(); i++){
        children[i]->draw(HourOfDay, DayOfYear);
    }
    //create the children
//
//    earth.draw(HourOfDay, DayOfYear);

}
