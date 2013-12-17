#ifndef SATURN_H
#define SATURN_H
#include "planet.h"
#include "Sphere.h"

class Saturn : public Planet
{
public:
    Saturn();
    void draw(float, float);
    Sphere outer_sphere;
};

#endif // SATURN_H
