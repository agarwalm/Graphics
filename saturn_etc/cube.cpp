#include "cube.h"
#include "Base.h"
#include "CCanvas.h"
#include <math.h>

cube::cube(float x) : x(x)
{
    draw(x);
}


void cube::draw(float x) {


   // glEnable(GL_NORMALIZE);

        //glTranslatef(2.0, 0.0, 0.0);

        glBegin(GL_QUADS);




 //back face blue

 glNormal3f(0,0,-1);
// glColor3f( 0.0, 0.0, 1.0 );

 glTexCoord2d(1.0/3, 3.0/4);
 glVertex3f( -x, -x, -x);       // bottom left

 glTexCoord2d(1.0/3, 1.0);
 glVertex3f( -x,  x, -x);       // top left

 glTexCoord2d(2.0/3, 1);
 glVertex3f(  x,  x, -x);       // top right

 glTexCoord2d(2.0/3, 3.0/4);
 glVertex3f(  x, -x, -x);       // bottom right



 //front face white

glNormal3f(0,0,1);
// glColor3f(   1.0,  1.0, 1.0 ); //bottom right
  glTexCoord2d(2.0/3, 2.0/4);
 glVertex3f(  x, -x, x );

// glColor3f( 1.0, 0.0, 0.0 );  //top right
 glTexCoord2d(2.0/3, 1.0/4);
 glVertex3f(  x,  x, x);

// glColor3f( 0.0, 1.0, 0.0 ); //top left
  glTexCoord2d(1.0/3, 1.0/4);
 glVertex3f( -x,  x, x );

 //glColor3f( 0.0, 0.0, 1.0 ); //bottom left
  glTexCoord2d(1.0/3, 2.0/4);
 glVertex3f( -x, -x, x );



 //Right face purple

 glNormal3f(1,0,0);
// glColor3f(  1.0,  0.0,  1.0 );

 glTexCoord2d(1, 2.0/4);
 glVertex3f( x, -x, -x ); //bottom back

 glTexCoord2d(1, 1.0/4);
 glVertex3f( x,  x, -x ); //top back

 glTexCoord2d(2.0/3, 1.0/4); //top front
 glVertex3f( x,  x,  x );

 glTexCoord2d(2.0/3, 2.0/4);
 glVertex3f( x, -x,  x ); //bottom front


 //left face green

 glNormal3f(-1,0,0);
// glColor3f(   0.0,  1.0,  0.0 ); //bottom right
 glTexCoord2d(1.0/3, 2.0/4);
 glVertex3f( -x, -x,  x );

// glColor3f(   1.0,  0.0,  0.0 ); //top right
 glTexCoord2d(1.0/3, 1.0/4);
 glVertex3f( -x,  x,  x );

 //glColor3f(   0.0,  0.0,  1.0 ); //top left
 glTexCoord2d(0, 1.0/4);
 glVertex3f( -x,  x, -x );

// glColor3f(   1.0,  1.0,  0.0 ); //bottom left
 glTexCoord2d(0,2.0/4);
 glVertex3f( -x, -x, -x );


 // Blue side - TOP

 glNormal3f(0,1,0);
// glColor3f(   0.0,  0.0,  1.0 );
 glTexCoord2d(2.0/3, 1.0/4);
 glVertex3f(  x,  x,  x ); //front right

 glTexCoord2d(2.0/3, 0);
 glVertex3f(  x,  x, -x );//back right

 glTexCoord2d(1.0/3, 0); //back left
 glVertex3f( -x,  x, -x );

 glTexCoord2d(1.0/3, 1.0/4); //front left
 glVertex3f( -x,  x,  x );


 // Red side - BOTTOM
 glNormal3f(0,-1,0);
// glColor3f(   1.0,  0.0,  0.0 );
 glTexCoord2d(2.0/3, 3.0/4);
 glVertex3f(  x, -x, -x ); //back right

 glTexCoord2d(2.0/3, 2.0/4);
 glVertex3f(  x, -x,  x ); //front right

 glTexCoord2d(1.0/3, 2.0/4);
 glVertex3f( -x, -x,  x ); //front left

 glTexCoord2d(1.0/3, 3.0/4);
 glVertex3f( -x, -x, -x ); //back left
 glEnd();

 glFlush();
// glutSwapBuffers();

}
