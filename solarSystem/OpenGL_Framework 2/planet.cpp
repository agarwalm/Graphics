#include "planet.h"
#include "Sphere.h"
#include "Base.h"
#include "Sphere.h"
#include "Sun.h"
#include "cube.h"

Planet::Planet()
{
    sphere = Sphere(20,10);
    cube = Cube(1.0);
}
