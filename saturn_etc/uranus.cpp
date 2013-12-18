#include "uranus.h"
#include "Base.h"
#include "Sphere.h"

uranus::uranus()
{
    glEnable(GL_TEXTURE_2D);
    QImage img;
    if( !img.load("/Users/mrigyaagarwal/Desktop/third_year/graphics/Graphics/saturn_etc/uranus.jpg")){
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

    sphere = Sphere(20,10);
}

void uranus::draw(float HourOfDay, float DayOfYear){

    //draw the earth
    glPushMatrix();

    glRotated(360.0*DayOfYear/(365.0*2), 0.0, 1.0, 0.0);
    glTranslated(12.0, 0.0, 0.0);
    glPushMatrix();
    glScaled(0.75, 0.75, 0.75);
    glRotated(360.0*HourOfDay*1.5/24.0, 0.0, 1.0, 0.0 );
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

