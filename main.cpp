#include <iostream>
#include <string>
using namespace std;

string word_tolower(string word)
{
    int n = word.length();
    for (int i = 0; i < n; i++){
        word[i] = tolower(word[i]);
    }
    return word;
}

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
    Object = word_tolower(Object);

    ObjectName = "circle";
    if (Object == ObjectName)
        return 1;
    ObjectName = "triangle";
    if (Object == ObjectName)
        return 2;
    ObjectName = "polygon";
    if (Object == ObjectName)
        return 3;
    return 4;
}
int main()
{
    string input, figureName;

    circle circ;

    input.clear();

    getline(cin, input);

    if (input.substr(0, 1) == " ") {
        input.erase(0, input.find_first_not_of(" "));
    }
    if (input.substr(input.find("(") - 1, 1) == " ") {
        input = input.erase(
                input.find(" "), input.find("(") - input.find(" "));
    }
    figureName = input.substr(0, input.find("("));

    switch (identify(figureName)) {
    case (1):
        input = input.erase(0, 6);
        circ.x = stof(input.substr(1, input.find(" ")));
        input = input.erase(0, input.find(" "));
        circ.y = stof(input.substr(1, input.find(",") - 1));
        input = input.erase(0, input.find(",") + 1);
        circ.radius = stof(input.substr(1, input.find(")") - 1));
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
