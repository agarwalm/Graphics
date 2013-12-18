#ifndef MARSMOON_H
#define MARSMOON_H

#include "planet.h"
#include "CCanvas.h"
#include "Base.h"
#include "Sphere.h"
#include "Sun.h"

class marsMoon : public Planet
{
public:
    marsMoon();
    void draw(float, float);
};

#endif // MARSMOON_H
