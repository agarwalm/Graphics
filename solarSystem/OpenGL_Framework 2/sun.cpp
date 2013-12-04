#include "Sun.h"
#include "earth.h"
#include "moon.h"
#include "Base.h"
#include "Sphere.h"



//create the children
Earth earth;


Sun::Sun()
{

//    children.insert(children.end(),(Planet)earth);
//    children.insert(children.end(), (Planet)moon);

}

void Sun::draw(double tau){


    glPushMatrix();

    glTranslated (0.0, 0.0, -5.0);

    glPushMatrix();

    glScaled (2.0, 2.0, 2.0);
    glColor3f(1.0, 1.0, 0.0);
    sphere.draw();

    glPopMatrix();

//    for (int i = 0; i < (sizeof(children)/sizeof(children[0])); i++){
//        children[i].draw();
//    }

    earth.draw(tau);

}
