#ifndef URANUS_H
#define URANUS_H
#include "planet.h"
#include "Sphere.h"
#include "Base.h"

class uranus : public Planet
{
public:
    uranus();
    void draw(float, float);
     Sphere outer_sphere;
};

#endif // URANUS_H
