#include <ctest.h>
#include <libgeometry/geometry.h>
#include <stdlib.h>

CTEST(P_and_A_of_circles, Perimeter)
{
    Circle_S Circle;
    Circle.radius = 2;

    float real = PerimeterOfACircle(Circle);

    float expP = 12.56636;

    ASSERT_DBL_NEAR(expP, real);
}
