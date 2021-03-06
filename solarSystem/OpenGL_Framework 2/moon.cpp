#include "moon.h"
#include "Base.h"
#include "Sphere.h"
#include "Sun.h"
#include "CCanvas.h"


Moon::Moon()
{

    QImage img;
    if( !img.load("/Users/mrigyaagarwal/Desktop/third_year/graphics/Graphics/solarSystem/OpenGL_Framework 2/moon.bmp")){
        qWarning("ERROR LOADING IMAGE");
    }

   // img.save("/Users/christinegraff/Documents/OpenGL_Framework 2/asdasd.bmp");

    //img.save("asd");
    //cout<< img << endl;
    img = QGLWidget::convertToGLFormat(img);
    glGenTextures(1, &name);
    glBindTexture(GL_TEXTURE_2D, name);
    glTexImage2D(GL_TEXTURE_2D,0, GL_RGBA, img.width(), img.height(), 0,GL_RGBA, GL_UNSIGNED_BYTE,img.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glGenerateMipmap(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, name);


    GLenum err;
        while ((err = glGetError()) != GL_NO_ERROR) {
            cerr << "OpenGL error: " << err << endl;
        }
}

void Moon::draw(float HourOfDay, float DayOfYear){

  //draw the moon

  //glPushMatrix();

    glRotated(360.0*12.0*DayOfYear/365.0, 0.0, 1.0, 0.0 );
    glTranslated (0.7, 0.0, 0.0 );

    glPushMatrix();

    glScaled(0.136,0.136, 0.136);
   // glColor3f(0.3, 0.7, 0.3);
    sphere.draw();

  glPopMatrix();
  glDisable(GL_TEXTURE_2D);

  glPopMatrix();


}
