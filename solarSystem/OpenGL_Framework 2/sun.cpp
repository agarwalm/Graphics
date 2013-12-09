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


//    children.insert(children.end(), (Planet)moon);
//texture
    QImage img;
    if(!img.load("/Users/mrigyaagarwal/Desktop/third_year/graphics/Graphics/solarSystem/OpenGL_Framework 2/sun.bmp")) {
        qWarning("ERROR LOADING IMAGE");
    }
    img.save("/Users/mrigyaagarwal/Desktop/third_year/graphics/Graphics/solarSystem/OpenGL_Framework 2/asdasd.bmp");
   // QImage img("/Users/mrigyaagarwal/Desktop/third_year/graphics/Graphics/solarSystem/OpenGL_Framework 2/sun.bmp");
   // QImage img("sun.bmp");
   // cout<< img << endl;
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
//    glDisable(GL_TEXTURE_2D);

//    file = fopen( "/Users/mrigyaagarwal/Desktop/third_year/graphics/Graphics/solarSystem/OpenGL_Framework 2/sun.bmp", "rb" );
//    //if ( file == NULL ) return 0;
//    width = 256;
//    height = 256;

//    data = (char *) malloc( width * height * 3 );
//    fread( data, width * height * 3, 1, file );
//    fclose( file );
//     glGenTextures( 1, &name );
//     glBindTexture( GL_TEXTURE_2D, name );
//     glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

//     glEnable(GL_TEXTURE_2D);
//     glBindTexture(GL_TEXTURE_2D, name);
    // glDisable(GL_TEXTURE_2D);

    //children.push_back(new Earth());


    GLenum err;
    while((err = glGetError())!= GL_NO_ERROR){
        cerr<< "OPenGL error: "<<err<<endl;
    }
}

//void Sun::draw(double tau){

void Sun::draw(float HourOfDay, float DayOfYear){
    //glPushMatrix();

    glTranslated (0.0, 0.0, -5.0);

    glPushMatrix();

    glScaled (2.0, 2.0, 2.0);
    glColor3f(1.0, 1.0, 0.0);



    sphere.draw();
     glDisable(GL_TEXTURE_2D);
     children.push_back(new Earth());

    glPopMatrix();

    for (int i = 0; i < children.size(); i++){
        children[i]->draw(HourOfDay, DayOfYear);
    }

//    earth.draw(HourOfDay, DayOfYear);

}
