#include "hollowcircle.h"
#include "Base.h"
#include "CCanvas.h"
#include <math.h>

HollowCircle::HollowCircle(double radius)
{

    r = radius;

}


void HollowCircle::draw()
{

    glBegin(GL_QUADS);

    glTexCoord2f(0,0);
    glVertex3f(-r,-r,0);

    glTexCoord2f(0,1.0);
    glVertex3f(-r,r,0);

    glTexCoord2f(1.0,1.0);
    glVertex3f(r,r,0);

    glTexCoord2f(1.0,0);
    glVertex3f(r,-r,0);

    glEnd();

}


