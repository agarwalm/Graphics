#include "cube.h"
#include "CCanvas.h"


Cube::Cube(float x) : x(x)
{
    draw(x);
}

void Cube::draw(float x) {


   // glEnable(GL_NORMALIZE);

     //   glTranslatef(2.0, 0.0, 0.0);

        glBegin(GL_QUADS);

//        glNormal3f(-1, 0, 0);// set the normals for the shading
//        glTexCoord2d(0.33, 0.25);
//        glVertex3f(-x,-x,-x);


//        glVertex3f(-x,-x,x);
//        glVertex3f(-x,x,x);

//        glNormal3f(-1, 0, 0);
//        glVertex3f(-x,-x,-x);
//        glVertex3f(-x,x,x);
//        glVertex3f(-x,x,-x);
//    ///////////
//        glNormal3f(0, 0, -1);
//        glVertex3f(x,x,-x);
//        glVertex3f(-x,-x,-x);
//        glVertex3f(-x,x,-x);

//        glNormal3f(0, 0, -1);
//        glVertex3f(x,x,-x);
//        glVertex3f(x,-x,-x);
//        glVertex3f(-x,-x,-x);
//    ////////////
//        glNormal3f(0, -1, 0);
//        glVertex3f(x,-x,x);
//        glVertex3f(-x,-x,-x);
//        glVertex3f(x,-x,-x);

//        glNormal3f(0, -1, 0);
//        glVertex3f(x,-x,x);
//        glVertex3f(-x,-x,x);
//        glVertex3f(-x,-x,-x);
//    ////////////
//        glNormal3f(1, 0, 0);
//        glVertex3f(x,x,x);
//        glVertex3f(x,-x,-x);
//        glVertex3f(x,x,-x);

//        glNormal3f(1, 0, 0);
//        glVertex3f(x,-x,-x);
//        glVertex3f(x,x,x);
//        glVertex3f(x,-x,x);
//    /////////////////////////
//        glNormal3f(0, 1, 0);
//        glVertex3f(x,x,x);
//        glVertex3f(x,x,-x);
//        glVertex3f(-x,x,-x);

//        glNormal3f(0, 1, 0);
//        glVertex3f(x,x,x);
//        glVertex3f(-x,x,-x);
//        glVertex3f(-x,x,x);
//    //////////////////
//        glNormal3f(0, 0, 1);
//        glVertex3f(-x,x,x);
//        glVertex3f(-x,-x,x);
//        glVertex3f(x,-x,x);

//        glNormal3f(0, 0, 1);
//        glVertex3f(x,x,x);
//        glVertex3f(-x,x,x);
//        glVertex3f(x,-x,x);
//        glEnd();

// glBegin(GL_POLYGON);

 //Front face blue

 glNormal3f(0,0,-1);
 glColor3f( 0.0, 0.0, 1.0 );
 glVertex3f( -x, -x, -x);       // P1
 glVertex3f( -x,  x, -x);       // P2
 glVertex3f(  x,  x, -x);       // P3
 glVertex3f(  x, -x, -x);       // P4

// glEnd();

 //Back face white
// glBegin(GL_POLYGON);
glNormal3f(0,0,1);
 glColor3f(   1.0,  1.0, 1.0 );
 glVertex3f(  x, -x, x );
 glColor3f( 1.0, 0.0, 0.0 );
 glVertex3f(  x,  x, x);
 glColor3f( 0.0, 1.0, 0.0 );
 glVertex3f( -x,  x, x );
 glColor3f( 0.0, 0.0, 1.0 );
 glVertex3f( -x, -x, x );

// glEnd();

 //Right face purple
// glBegin(GL_POLYGON);
 glNormal3f(1,0,0);
 glColor3f(  1.0,  0.0,  1.0 );
 glVertex3f( x, -x, -x );
 glVertex3f( x,  x, -x );
 glVertex3f( x,  x,  x );
 glVertex3f( x, -x,  x );
// glEnd();

 //left face green
// glBegin(GL_POLYGON);
 glNormal3f(-1,0,0);
 glColor3f(   0.0,  1.0,  0.0 );
 glVertex3f( -x, -x,  x );
 glVertex3f( -x,  x,  x );
 glVertex3f( -x,  x, -x );
 glVertex3f( -x, -x, -x );
 //glEnd();

 // Blue side - TOP
// glBegin(GL_POLYGON);
 glNormal3f(0,1,0);
 glColor3f(   0.0,  0.0,  1.0 );
 glVertex3f(  x,  x,  x );
 glVertex3f(  x,  x, -x );
 glVertex3f( -x,  x, -x );
 glVertex3f( -x,  x,  x );
//glEnd();

 // Red side - BOTTOM
 //glBegin(GL_POLYGON);
 glNormal3f(0,-1,0);
 glColor3f(   1.0,  0.0,  0.0 );
 glVertex3f(  x, -x, -x );
 glVertex3f(  x, -x,  x );
 glVertex3f( -x, -x,  x );
 glVertex3f( -x, -x, -x );
 glEnd();

 glFlush();
// glutSwapBuffers();

}
