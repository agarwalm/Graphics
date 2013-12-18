#ifndef JUPITERMOON_H
#define JUPITERMOON_H
#include "planet.h"
#include "CCanvas.h"
#include "Base.h"
#include "Sphere.h"
#include "Sun.h"


class JupiterMoon : public Planet
{
public:
    JupiterMoon();
    void draw(float, float);
};

#endif // JUPITERMOON_H
