#include "earth.h"
#include "Base.h"
#include "Sphere.h"
#include "Sun.h"
#include "Moon.h"

Earth::Earth()
{
}

Moon moon;

//void Earth::draw(double tau){
void Earth::draw(float HourOfDay, float DayOfYear){
    //draw the earth
    glRotated(360.0*DayOfYear/365.0, 0.0, 1.0, 0.0); //rotation around the sun
    glTranslated(4.0, 0.0, 0.0);

    glPushMatrix();
//(sin(23.0*PI/180)
    glRotated(360.0*HourOfDay/24.0, 0.0, 1, 0.0 ); //rotation on its own axis
    glScaled(0.5, 0.5, 0.5);
    glColor3f(0.2, 0.2, 1.0);
    sphere.draw();

    glPopMatrix();

    //draw the children
    moon.draw(HourOfDay, DayOfYear);
}
