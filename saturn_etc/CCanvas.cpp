#include "CCanvas.h"
#include "Base.h"
#include "Sphere.h"
#include "Sun.h"
#include "skybox.h"
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
  skybox = new Skybox();
  center.z()=-1;

  angle = M_PI/2.0;
  angle2 = M_PI/2.0;
  up.y() = 1;
  currentView = 0;
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
//        s.normalize();

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
  glEnable(GL_COLOR_MATERIAL);
  // set model-view matrix

  glMatrixMode (GL_PROJECTION);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();


  GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
  GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat specular[] = { 0.0, 1.0, 1.0, 1.0 };
  GLfloat position[] = { 0.0, 4, 3, 1.0 };

  GLfloat ambient1[] = { 0.0, 0.0, 0.0, 1.0 };
  GLfloat diffuse1[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat specular1[] = { 1.0, 1.0, 1.0, 1.0 };


  GLfloat position1[] = { 0.0, 0, -7, 1 };

//  glLightfv( GL_LIGHT0, GL_AMBIENT, ambient );
//  glLightfv( GL_LIGHT0, GL_DIFFUSE, diffuse );
//  glLightfv( GL_LIGHT0, GL_SPECULAR, specular );
//  glLightfv( GL_LIGHT0, GL_POSITION, position );
//  glEnable( GL_LIGHTING );
//  glEnable( GL_LIGHT0 );



  glLightfv( GL_LIGHT1, GL_AMBIENT, ambient1 );
  glLightfv( GL_LIGHT1, GL_DIFFUSE, diffuse1 );
  glLightfv( GL_LIGHT1, GL_SPECULAR, specular1 );
  glLightfv( GL_LIGHT1, GL_POSITION, position1 );
  glEnable( GL_LIGHTING );
  glEnable( GL_LIGHT1 );


  glPushMatrix();
  glLoadIdentity();
  lookAt( 0,0,0, //eye position
          center.x(),center.y(),center.z(),  //center
          up.x(),up.y(),up.z() );
  //glTranslated(-eye.x(),-eye.y(),-eye.z());
    glDisable(GL_LIGHTING);
    skybox->draw();
//    glEnable(GL_LIGHTING);

    glPopMatrix();

//  lookAt( eye.x(),eye.y(),eye.z(), //eye position
//          center.x(),center.y(),center.z(),  //center
//          up.x(),up.y(),up.z() );     //up vector


  lookAt( eye.x(),eye.y(),eye.z(), //eye position
          eye.x()+center.x(),eye.y()+center.y(),eye.z()+center.z(),  //center
          up.x(),up.y(),up.z() );     //up vector

  if (currentView == 1){


      glRotated(-90.0, 1.0, 0,0);
      glTranslated(0,5,7.0);
  }


  //  glTranslatef(0.0, 0.0, -8.0);

  //glRotatef(15.0, 1.0, 0.0, 0.0);


/*  glClearColor(0.0f,0.0f,0.0f,1.0f);          // We'll Clear To The Color Of The Fog ( Modified )

  GLfloat fogColor[4]= {0.0f, 0.0f, 0.0f, 1.0f};

  glFogi(GL_FOG_MODE, GL_EXP);        // Fog Mode
  glFogfv(GL_FOG_COLOR, fogColor);            // Set Fog Color
  glFogf(GL_FOG_DENSITY, 0.2f);              // How Dense Will The Fog Be
  glHint(GL_FOG_HINT, GL_DONT_CARE);          // Fog Hint Value
  glFogf(GL_FOG_START, 1.0f);             // Fog Start Depth
  glFogf(GL_FOG_END, 5.0f);               // Fog End Depth
  glEnable(GL_FOG); */                  // Enables GL_FOG








  sun->draw(HourOfDay, DayOfYear);


  if (paused == false){

  HourOfDay += AnimateIncrement;
   // DayOfYear = HourOfDay/24;
    DayOfYear += AnimateIncrement/24.0;
    HourOfDay = HourOfDay - ((int)(HourOfDay/24))*24;
    DayOfYear = DayOfYear - ((int)(DayOfYear/365))*365;

    slider->setValue(DayOfYear);

  }



  tau += 1.0;
  //tau2 += 0.1;
}

void CCanvas::setDate(int val){

    numOfDays = val;
    DayOfYear = numOfDays;
}

void CCanvas::pause(){
    if (paused == false){
        paused = true;
    }
    else{
        paused = false;
    }
}

void CCanvas::lookup(){

//    up.z()=1;
//    up.y() = 0;
//    up.x() = 0;
    currentView = 1;

//    eye.x()=0;
//    eye.y() = 1;
//    eye.z() = -7;
//angle=0;
//center.x()=0;center.y()=-1;center.z()=0;

}

void CCanvas::lookdown(){




}

void CCanvas::upArrow(){
//    angle2+=0.1;
//    center.z()=sin(angle2)*sin(angle);
//    center.x()=sin(angle2)*cos(angle);
//    center.y()=cos(angle2);
//    angle2+=0.1;
//    center.y()=-cos(angle2);
//    center.z()=-sin(angle2);

}
void CCanvas::downArrow(){
//    angle2-=0.1;
//    center.z()=sin(angle2)*sin(angle);
//    center.x()=sin(angle2)*cos(angle);
//    center.y()=cos(angle2);
//    angle2-=0.1;
//    center.y()=-cos(angle2);
//    center.z()=-sin(angle2);

}
void CCanvas::rightArrow(){
    angle+=0.1;

//    if(currentView ==0){
        center.x()=-cos(angle);
        center.z()=-sin(angle);
//    }
//    else if(currentView == 1){
//        center.x()=-cos(angle);
//        center.y()=-sin(angle);

//    }
//    center.z()=sin(angle2)*sin(angle);
//    center.x()=sin(angle2)*cos(angle);
//    center.y()=cos(angle2);


}
void CCanvas::leftArrow(){
    angle-=0.1;

//   if(currentView ==0){
    center.x()=-cos(angle);
    center.z()=-sin(angle);
//   }

//   else if(currentView == 1){

//       center.x()=-cos(angle);
//       center.y()=-sin(angle);

//   }
//    center.z()=sin(angle2)*-sin(angle);
//    center.x()=sin(angle2)*-cos(angle);
//    center.y()=cos(angle2);
}

void CCanvas::forward(){
    eye-= 0.1*center;
    std::cout<<eye<<std::endl;
}
void CCanvas::back(){
    eye+= 0.1*center;
std::cout<<eye<<std::endl;

}

void CCanvas :: passSlider(QSlider* s){

    slider = s;

}

