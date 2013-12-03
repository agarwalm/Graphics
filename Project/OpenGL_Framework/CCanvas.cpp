#include "CCanvas.h"
#include "Base.h"
#include "Sphere.h"

using namespace std;

//-----------------------------------------------------------------------------

void CCanvas::initializeGL()
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.5f);			          // Black Background
  glClearDepth(1.0f);									                // Depth Buffer Setup
  glEnable(GL_DEPTH_TEST);							              // Enables Depth Testing
  glDepthFunc(GL_LEQUAL);								              // The Type Of Depth Testing To Do
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
};

//-----------------------------------------------------------------------------


void  CCanvas::glPerspective(
        const GLdouble fovy,
        const GLdouble aspect,
        const GLdouble zNear,
        const GLdouble zFar)
{
    const GLdouble d=1.0/tan(fovy/360.0*PI);
    const GLdouble delta=zNear-zFar;

    GLdouble *mat=new GLdouble[16];

    mat[0]=d/aspect;
    mat[1]=0;
    mat[2]=0;
    mat[3]=0;

    mat[4]=0;
    mat[5]=d;
    mat[6]=0;
    mat[7]=0;

    mat[8]=0;
    mat[9]=0;
    mat[10]=(zNear+zFar)/delta;
    mat[11]=-1;

    mat[12]=0;
    mat[13]=0;
    mat[14]=2*zNear*zFar/delta;
    mat[15]=0;


    glMultMatrixd(mat);

    delete[] mat;
}


void CCanvas::  lookAt(const GLdouble eyex,
                       const GLdouble eyey,
                       const GLdouble eyez,
                       const GLdouble centerx,
                       const GLdouble centery,
                       const GLdouble centerz,
                       const GLdouble upx,
                       const GLdouble upy,
                       const GLdouble upz)
{

    //float matrix wiht 16 floats
    //camera matrix
    //put the right values in the right columns and rows
    GLdouble *mat=new GLdouble[16];

//TODO add computation for the lookat here


    glMultMatrixd(mat);

    //camera matrix gets multiplied by the right openGL matrix
    delete[] mat;


}

//called when the window is resized
//don't change this.. except maybe change the clipping plane
void CCanvas::resizeGL(int width, int height)
{
  // set up the window-to-viewport transformation
  glViewport( 0,0, width,height );

  // vertical camera opening angle
  double beta = 90.0;

  // aspect ratio
  double gamma;
  if (height > 0)
    gamma = width/(double)height;
  else
    gamma = width;

  // front and back clipping plane at
  double n = -1.0;
  double f = -10.0;
  
  // frustum corners
  double t = -tan(beta*3.14159/360.0) * n;
  double b = -t;
  double r = gamma * t;
  double l = -r;

  // set projection matrix
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum( l,r , b,t , -n,-f );

  // alternatively, directly from alpha and gamma
//  glPerspective( beta, gamma, -n, -f );
}

//-----------------------------------------------------------------------------

void CCanvas::paintGL()
{
//    glEnable(GL_LIGHTING);
//    glShadeModel(GL_SMOOTH);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  // clear screen and depth buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // set model-view matrix
  glMatrixMode(GL_MODELVIEW);
  //makes sure that the current thing in the stack is the identity
  glLoadIdentity();
  //lookAt( 0,0,0,  0,0,-1,  0,1,0 );     // camera position , "look at" point , view-up vector




  // set up a sphere (sun)
  Sphere sphere (20,10);

  //every time you push something, pop it later. make sure the stack is always empty!
  glPushMatrix();
glColor3f(1.0, 1.0, 0.0);
  // transform and draw sphere
  glTranslated (0.0, 0.0, -5.0);
 // glRotated ( tau, 0,0,1 );
  //glScaled (2.0, 2.0, 2.0);


//  glPushMatrix();

//  glRotated(0,0,0,0);

  //glScaled (2.0, 2.0, 2.0);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  sphere.draw();
  //glPopMatrix();

  //glPushMatrix();
  // set up another sphere (Earth)
  Sphere sphere2 (20,10);

  // transform and draw sphere
  glRotated ( tau2, 0,0,1 );
  glTranslated (2.0, 2.0, 0);
  //glScaled (0.5, 0.5, 0.5);


  glPushMatrix();
  glScaled (0.3, 0.3, 0.3);


  //
  sphere2.draw();
  //glPopMatrix();

  glPushMatrix();
//Moon
  Sphere sphere3 (20,10);

  // transform and draw sphere
  glRotated ( tau2, 0,0,1 );
  glTranslated (2.0, 2.0, 0);
  //glScaled (0.5, 0.5, 0.5);


  glPushMatrix();
  glScaled (0.3, 0.3, 0.3);


  //
  sphere3.draw();
  glPopMatrix();


  tau += 1.0;
  tau2 += 0.1;
}
