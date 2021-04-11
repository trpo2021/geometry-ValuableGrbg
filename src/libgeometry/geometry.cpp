#include <cmath>
#include <iostream>
#include <libgeometry/geometry.h>
#include <string>
using namespace std;

double circle_perimeter(double radius)
{
    double perimeter;
    perimeter = 2 * 3.14 * radius;
    return perimeter;
}

double circle_area(double radius)
{
    double area;
    area = 3.14 * radius * radius;
    return area;
}

void find_circle_param(mas_figures circl, double* perimeter, double* area)
{
    *perimeter = circle_perimeter(circl.circ.radius);
    *area = circle_area(circl.circ.radius);
}

double distance_between_points(double x1, double x2, double y1, double y2)
{
    double rez = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return rez;
}

void find_triangle_param(mas_figures triang, double* perimeter, double* area)
{
    double x1 = triang.triag.point_1[0];
    double x2 = triang.triag.point_2[0];
    double x3 = triang.triag.point_3[0];
    double y1 = triang.triag.point_1[1];
    double y2 = triang.triag.point_2[1];
    double y3 = triang.triag.point_3[1];

    *perimeter = distance_between_points(x1, x2, y1, y2)
            + distance_between_points(x2, x3, y2, y3)
            + distance_between_points(x3, x1, y3, y1);

    *area = abs(((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2);
}

void print_circle(mas_figures* circl, double* perimeter, double* area)
{
    cout << circl->order_number << "."
         << "circle(" << circl->circ.x << ' ' << circl->circ.y << ", "
         << circl->circ.radius << ")" << endl;
    find_circle_param(*circl, perimeter, area);
    cout << "Perimetr: " << *perimeter << endl;
    cout << "Area: " << *area << endl;
}

void print_triangle(mas_figures* triang, double* perimeter, double* area)
{
    cout << triang->order_number << "."
         << "triangle((" << triang->triag.point_1[0] << ' '
         << triang->triag.point_1[1] << "," << triang->triag.point_2[0] << ' '
         << triang->triag.point_2[1] << "," << triang->triag.point_3[0] << ' '
         << triang->triag.point_3[1] << "," << triang->triag.point_4[0] << ' '
         << triang->triag.point_4[1] << "))" << endl;
    find_triangle_param(*triang, perimeter, area);
    cout << "Perimeter: " << *perimeter << endl;
    cout << "Area: " << *area << endl;
}
