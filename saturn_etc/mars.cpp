#include "mars.h"
#include "Base.h"
#include "Sphere.h"
#include "marsmoon.h"

mars::mars()
{
    glEnable(GL_TEXTURE_2D);
    QImage img;
    if( !img.load("/Users/mrigyaagarwal/Desktop/third_year/graphics/Graphics/saturn_etc/mars.jpg")){
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

    children.push_back(new marsMoon());

    sphere = Sphere(20,10);
}

void mars::draw(float HourOfDay, float DayOfYear){

    //draw the earth
    glPushMatrix();

    glRotated(360.0*DayOfYear/(365.0*5), 0.0, 1.0, 0.0);
    glTranslated(6.0, 0.0, 0.0);
    glPushMatrix();
    glScaled(0.7, 0.7, 0.7);
    glRotated(360.0*HourOfDay*1.2/24.0, 0.0, 1.0, 0.0 );
    glRotated(90,1.0,0,0);
    //glBindTexture(GL_TEXTURE_2D, name);
    //glColor3f(0.0, 0.0, 2.0);

    sphere.draw();
    //box.draw(1.0f);

    // glDisable(GL_TEXTURE_2D);
    glPopMatrix();



    for (int i = 0; i <children.size(); i++){
        children[i]->draw(HourOfDay, DayOfYear);
    }

    glPopMatrix();
}

