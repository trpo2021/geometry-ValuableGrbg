#include <ctest.h>
#include <libgeometry/geometry.h>

#include <stdlib.h>

CTEST(P_and_a_of_circle, Perimeter)
{
    double radius = 2;

    double real = circle_perimeter(radius);

    double expP = 12.56636;

    ASSERT_DBL_NEAR(expP, real);
}
