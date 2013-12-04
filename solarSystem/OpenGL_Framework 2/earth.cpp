#include "earth.h"
#include "Base.h"
#include "Sphere.h"
#include "Sun.h"
#include "Moon.h"

Earth::Earth()
{
}

Moon moon;

void Earth::draw(double tau){

    //draw the earth
    glRotated(tau, 0,0,1);
    glTranslated(3.0, 3.0, 0);

    glPushMatrix();

    glRotated(tau, 0,0,1);
    glScaled(0.5, 0.5, 0.5);
    glColor3f(0.0, 0.0, 2.0);
    sphere.draw();

    glPopMatrix();

    //draw the children
    moon.draw(tau);
}
