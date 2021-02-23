#include <iostream>
#include <string>

using namespace std;

struct circle {
    int x;
    int y;
    int radius;
};

void find_circle_param(circle circ)
{
    float perimetr = 2 * 3.14 * circ.radius;
    float area = 3.14 * circ.radius * circ.radius;

    cout << " Perimetr: " << perimetr << endl;
    cout << " Area: " << area << endl;
}

int identify(string Object)
{
    string ObjectName;
    ObjectName = "circle";
    if (_stricmp(Object.c_str(), ObjectName.c_str()) == 0)
        return 1;
    ObjectName = "triangle";
    if (_stricmp(Object.c_str(), ObjectName.c_str()) == 0)
        return 2;
    ObjectName = "polygon";
    if (_stricmp(Object.c_str(), ObjectName.c_str()) == 0)
        return 3;
    return 4;
}
int main()
{
    string Object, ObjectName;

    circle circ;

    Object.clear();

    getline(cin, Object);

    if (Object.substr(0, 1) == " ") {
        Object.erase(0, Object.find_first_not_of(" "));
    }
    if (Object.substr(Object.find("(") - 1, 1) == " ") {
        Object = Object.erase(
                Object.find(" "), Object.find("(") - Object.find(" "));
    }
    ObjectName = Object.substr(0, Object.find("("));

    switch (identify(ObjectName)) {
    case (1):
        Object = Object.erase(0, 6);
        circ.x = stof(Object.substr(1, Object.find(" ")));
        Object = Object.erase(0, Object.find(" "));
        circ.y = stof(Object.substr(1, Object.find(",") - 1));
        Object = Object.erase(0, Object.find(",") + 1);
        circ.radius = stof(Object.substr(1, Object.find(")") - 1));
        cout << "x = " << circ.x << endl;
        cout << "y = " << circ.y << endl;
        cout << "radius = " << circ.radius << endl;
        break;
    case (2):
        cout << "it's triangle" << endl;
        break;
    case (3):
        cout << "it's polygon" << endl;
        break;
    case (4):
        cout << "Error in name of figure!";
    }
}
