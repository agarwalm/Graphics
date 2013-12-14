#ifndef ATMOSPHERE_H
#define ATMOSPHERE_H
#include "Sphere.h"
#include "planet.h"

class Atmosphere : public Planet
{
public:
    Atmosphere();
    void draw(float, float);
    Sphere sphere;
    double tau;
};

#endif // ATMOSPHERE_H
