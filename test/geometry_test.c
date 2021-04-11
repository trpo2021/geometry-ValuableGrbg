#include <ctest.h>
#include <libgeometry/geometry.h>
#include <stdlib.h>

CTEST(Perimeter_and_area_of_a_circle, Perimeter)
{
    circle Circle;
    Circle.radius = 2;

    double real = circle_perimeter(Circle.radius);

    double expP = 12.56636;

    ASSERT_DBL_NEAR(expP, real);
}
