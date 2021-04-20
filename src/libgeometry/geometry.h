#pragma once

enum Figures { CIRCLE, TRIANGLE, ERROR };

struct circle {
    float x;
    float y;
    float radius;
};

struct triangle {
    float point_1[2];
    float point_2[2];
    float point_3[2];
    float point_4[2];
};

struct mas_figures {
    Figures tag;
    int order_number;
    union {
        struct circle circ;
        struct triangle triag;
    };
};

double distance_between_points(double x1, double x2, double y1, double y2);

void find_circle_param(mas_figures circl, double* perimeter, double* area);

void find_triangle_param(mas_figures triang, double* perimeter, double* area);

void print_circle(mas_figures* circl, double* perimeter, double* area);

void print_triangle(mas_figures* triang, double* perimeter, double* area);

double circle_area(double radius);

double circle_perimeter(double radius);

double
triangle_area(double x1, double x2, double x3, double y1, double y2, double y3);

double triangle_perimeter(
        double x1, double x2, double x3, double y1, double y2, double y3);