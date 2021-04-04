#include <cmath>
#include <iostream>
#include <libgeometry/geometry.h>
#include <string>
using namespace std;

void find_circle_param(circle circ, float* perimeter, float* area)
{
    *perimeter = 2 * 3.14 * circ.radius;
    *area = 3.14 * circ.radius * circ.radius;
}

double distance_between_points(double x1, double x2, double y1, double y2)
{
    double rez = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return rez;
}

void find_triangle_param(triangle triag, float* perimeter, float* area)
{
    double x1 = triag.point_1[0];
    double x2 = triag.point_2[0];
    double x3 = triag.point_3[0];
    double y1 = triag.point_1[1];
    double y2 = triag.point_2[1];
    double y3 = triag.point_3[1];

    *perimeter = distance_between_points(x1, x2, y1, y2)
            + distance_between_points(x2, x3, y2, y3)
            + distance_between_points(x3, x1, y3, y1);

    *area = abs(((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2);
}

void print_circle(circle* circ, float* perimeter, float* area)
{
    cout << "circle(" << circ->x << ' ' << circ->y << ", " << circ->radius
         << ")" << endl;
    find_circle_param(*circ, perimeter, area);
    cout << "Perimetr: " << *perimeter << endl;
    cout << "Area: " << *area << endl;
}

void print_triangle(triangle* triag, float* perimeter, float* area)
{
    cout << "triangle((" << triag->point_1[0] << ' ' << triag->point_1[1] << ","
         << triag->point_2[0] << ' ' << triag->point_2[1] << ","
         << triag->point_3[0] << ' ' << triag->point_3[1] << ","
         << triag->point_4[0] << ' ' << triag->point_4[1] << "))" << endl;
    find_triangle_param(*triag, perimeter, area);
    cout << "Perimeter: " << *perimeter << endl;
    cout << "Area: " << *area << endl;
}
