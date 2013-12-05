#include "moon.h"
#include "Base.h"
#include "Sphere.h"
#include "Sun.h"
#include "CCanvas.h"


Moon::Moon()
{
}

//void Moon::draw(double tau){
void Moon::draw(float HourOfDay, float DayOfYear){
  //draw the moon

  glPushMatrix();

  glRotated(360.0*12.0*DayOfYear/365.0, 0.0, 1.0, 0.0 );
  glTranslated (0.7, 0.0, 0.0 );

  glPushMatrix();

  glScaled(0.136,0.136, 0.136);
  glColor3f(0.3, 0.7, 0.3);
  sphere.draw();

  glPopMatrix();
  glPopMatrix();

}
