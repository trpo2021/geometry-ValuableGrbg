#pragma once

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

enum Figures { CIRCLE, TRIANGLE, ERROR };

void find_circle_param(circle circ, float* perimeter, float* area);

void find_triangle_param(triangle triag, float* perimeter, float* area);

void print_circle(circle* circ, float* perimeter, float* area);

void print_triangle(triangle* triag, float* perimeter, float* area);
