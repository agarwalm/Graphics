#ifndef MARS_H
#define MARS_H
#include "planet.h"
#include "Sphere.h"
#include "Base.h"

class mars : public Planet
{
public:
    mars();
    void draw(float, float);
     Sphere outer_sphere;
};

#endif // MARS_H
