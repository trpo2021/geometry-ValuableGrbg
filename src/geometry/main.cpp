#include <algorithm>
#include <iostream>
#include <libgeometry/geometry.h>
#include <libgeometry/parse.h>
#include <string>
using namespace std;

int main()
{
    string input, figureName;

    int number_of_figures;
    cout << "Input the number of figures" << endl;
    cin >> number_of_figures;
    cin.sync();
    mas_figures figures[number_of_figures];

    for (int i = 0; i < number_of_figures; i++) {
        getline(cin, input);
        figureName = parse_name(&input);

        switch (identify(figureName)) {
        case CIRCLE:
            figures[i].tag = CIRCLE;
            figures[i].order_number = i + 1;
            parse_circle(input, &figures[i]);
            break;
        case TRIANGLE:
            figures[i].tag = TRIANGLE;
            figures[i].order_number = i + 1;
            parse_triangle(input, &figures[i]);
            break;
        case ERROR:
            cout << input << endl;
            cout << '^' << endl;
            cout << "Error in name of figure!";
        }
    }

    float perimeter, area;
    cout << endl;
    for (int i = 0; i < number_of_figures; i++) {
        if (figures[i].tag == CIRCLE)
            print_circle(&figures[i], &perimeter, &area);
        if (figures[i].tag == TRIANGLE)
            print_triangle(&figures[i], &perimeter, &area);
    }
}
