#include "geometry.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void find_circle_param(circle circ, float* perimeter, float* area)
{
    *perimeter = 2*3.14*circ.radius;
    *area = 3.14 * circ.radius *circ.radius;

    
}

void find_triangle_param(triangle triag, float* perimeter, float* area)
{
    *perimeter = sqrt(pow((triag.point_2[0] - triag.point_1[0]), 2)
                     +pow((triag.point_2[1] - triag.point_1[1]), 2))

               + sqrt(pow((triag.point_3[0] - triag.point_2[0]), 2)
                     +pow((triag.point_3[1] - triag.point_2[1]), 2))

               + sqrt(pow((triag.point_1[0] - triag.point_3[0]), 2)
                     +pow((triag.point_1[1] - triag.point_3[1]), 2));

    *area = abs(((triag.point_1[0]-triag.point_3[0])*(triag.point_2[1]-triag.point_3[1])-(triag.point_2[0]-triag.point_3[0])*(triag.point_1[1]-triag.point_3[1]))/2);
}

void print_circle(circle* circ, float* perimeter, float* area)
{
    cout << "circle(" << circ->x << ' ' << circ->y << ", " << circ->radius << ")" << endl;
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
