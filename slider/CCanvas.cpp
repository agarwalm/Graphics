#include "CCanvas.h"
#include "Base.h"
#include "Sphere.h"
#include "Sun.h"
#include "planet.h"
#include "GLRender.h"
#include <QString>
#include <QImage>
#include <QSpinBox>
#include <QSlider>


using namespace std;

//-----------------------------------------------------------------------------

void CCanvas::initializeGL()
{

  glClearColor(0.0f, 0.0f, 0.0f, 0.5f);			          // Black Background
  glClearDepth(1.0f);									                // Depth Buffer Setup
  glEnable(GL_DEPTH_TEST);							              // Enables Depth Testing
  glDepthFunc(GL_LEQUAL);								              // The Type Of Depth Testing To Do
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
  HourOfDay = 0.0;
  DayOfYear = 0.0;
  AnimateIncrement = 1.0;

  sun=new Sun();
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


    GLdouble *mat=new GLdouble[16];

    Point3d p(centerx, centery, centerz);
        Point3d eye(eyex, eyey, eyez);
        Point3d vup(upx, upy, upz);
        Point3d vpn = eye-p;
        vpn.normalize();

        Point3d s = vup^vpn;

        mat[0] = s.x();
        mat[1] = upx;
        mat[2] = vpn.x();
        mat[3] = 0;

        mat[4] = s.y();
        mat[5] = upy;
        mat[6] = vpn.y();
        mat[7] = 0;

        mat[8] = s.z();
        mat[9] = upz;
        mat[10] = vpn.z();
        mat[11] = 0;

        mat[12] = eyex;
        mat[13] = eyey;
        mat[14] = eyez;
        mat[15] = 1;

    glMultMatrixd(mat);

    delete[] mat;


}

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
  double f = -100.0;
  
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
bool paused = false;
void CCanvas::paintGL()
{
    glEnable(GL_TEXTURE_2D);

    if(sun==NULL) return;

//   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // clear screen and depth buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glShadeModel(GL_SMOOTH);
  //glEnable(GL_COLOR_MATERIAL);
  // set model-view matrix

  glMatrixMode (GL_PROJECTION);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glPushMatrix();
  lookAt( 0,0,0,  0,0,-1,  0,1,0 );     // camera position , "look at" point , view-up vector
//  glTranslatef(0.0, 0.0, -8.0);

  //glRotatef(15.0, 1.0, 0.0, 0.0);

  GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
  GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat position[] = { 0.0, 4, -5, 1.0 };

  GLfloat position1[] = { 0.0, 0, 0, 1 };

  glLightfv( GL_LIGHT0, GL_AMBIENT, ambient );
  glLightfv( GL_LIGHT0, GL_DIFFUSE, diffuse );
  glLightfv( GL_LIGHT0, GL_SPECULAR, specular );
  glLightfv( GL_LIGHT0, GL_POSITION, position );
  glEnable( GL_LIGHTING );
  glEnable( GL_LIGHT0 );


  glLightfv( GL_LIGHT1, GL_AMBIENT, ambient );
  glLightfv( GL_LIGHT1, GL_DIFFUSE, diffuse );
  glLightfv( GL_LIGHT1, GL_SPECULAR, specular );
  glLightfv( GL_LIGHT1, GL_POSITION, position1 );
  glEnable( GL_LIGHTING );
  glEnable( GL_LIGHT1 );

//  cout << "got here"<<endl;





  sun->draw(HourOfDay, DayOfYear);

  if (paused == false){

  HourOfDay += AnimateIncrement;
   // DayOfYear = HourOfDay/24;
    DayOfYear += AnimateIncrement/24.0;
    HourOfDay = HourOfDay - ((int)(HourOfDay/24))*24;
    DayOfYear = DayOfYear - ((int)(DayOfYear/365))*365;

  }

    cout<<"the date is: "<<numOfDays<<endl;


  //tau += 1.0;
  //tau2 += 0.1;
}

void CCanvas::setDate(int val){

    numOfDays = val;
}

void CCanvas::pause(){
    if (paused == false){
        paused = true;
    }
    else{
        paused = false;
    }
}
