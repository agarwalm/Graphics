#ifndef JUPITER_H
#define JUPITER_H
#include "planet.h"
#include "Sphere.h"
#include "Base.h"

class Jupiter : public Planet
{
public:
    Jupiter();
    void draw(float, float);
     Sphere outer_sphere;
};

#endif // JUPITER_H
