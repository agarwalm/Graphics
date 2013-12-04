#include "moon.h"
#include "Base.h"
#include "Sphere.h"
#include "Sun.h"
#include "CCanvas.h"


Moon::Moon()
{
}

void Moon::draw(double tau){

  //draw the moon

  glPushMatrix();

  glRotated(tau,0,0,1);
  glTranslated (1.0, 1.0, 0);

  glPushMatrix();

  glScaled(0.2,0.2, 0.2);
  glColor3f(1.0,1.0,1.0);
  sphere.draw();

  glPopMatrix();
  glPopMatrix();

}
