#include <algorithm>
#include <iostream>
#include <libgeometry/geometry.h>
#include <libgeometry/parse.h>
#include <string>
using namespace std;

int main()
{
    string input, figureName;
    getline(cin, input);

    figureName = parse_name(input);

    float perimeter, area;
    switch (identify(figureName)) {
    case CIRCLE:
        circle circ;
        parse_circle(input, &circ);
        print_circle(&circ, &perimeter, &area);
        break;
    case TRIANGLE:
        triangle triag;
        parse_triangle(input, &triag);
        print_triangle(&triag, &perimeter, &area);
        break;
    case ERROR:
        cout << input << endl;
        cout << '^' << endl;
        cout << "Error in name of figure!";
    }
}
