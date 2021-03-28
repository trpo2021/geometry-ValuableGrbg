#include <algorithm>
#include <iostream>
#include <libgeometry/parse.h>
#include <string>

std::string word_tolower(std::string word)
{
    int n = word.length();
    for (int i = 0; i < n; i++) {
        word[i] = tolower(word[i]);
    }
    return word;
}

Figures identify(std::string figure)
{
    std::string figureName;
    figure = word_tolower(figure);

    figureName = "circle";
    if (figure == figureName)
        return CIRCLE;

    figureName = "triangle";
    if (figure == figureName)
        return TRIANGLE;

    return ERROR;
}

void parse_circle(std::string input, circle* circ)
{
    size_t end;
    input = input.erase(0, 6);
    if (input[0] == '(') {
        input.erase(0, 1);
        circ->x = stod(input, &end);
        input = input.erase(0, end);
        circ->y = stod(input, &end);
        input = input.erase(0, end + 1);
        circ->radius = stod(input, &end);
    };
}

void parse_triangle(std::string input, triangle* triag)
{
    size_t end;
    input = input.erase(0, 8);
    if ((input[0] == '(') && (input[1] == '(')) {
        input = input.erase(0, 2);
        replace(input.begin(), input.end(), ',', ' '); // remove all ','
        triag->point_1[0] = stod(input, &end);
        input.erase(0, end);
        triag->point_1[1] = stod(input, &end);
        input.erase(0, end);
        triag->point_2[0] = stod(input, &end);
        input.erase(0, end);
        triag->point_2[1] = stod(input, &end);
        input.erase(0, end);
        triag->point_3[0] = stod(input, &end);
        input.erase(0, end);
        triag->point_3[1] = stod(input, &end);
        input.erase(0, end);
        triag->point_4[0] = stod(input, &end);
        input.erase(0, end);
        triag->point_4[1] = stod(input, &end);
        input.erase(0, end);
    }
}

std::string parse_name(std::string input)
{
    std::string figureName;
    if (input.substr(0, 1) == " ") {
        input.erase(0, input.find_first_not_of(" "));
    }
    if (input.substr(input.find("(") - 1, 1) == " ") {
        input = input.erase(input.find(" "), input.find("(") - input.find(" "));
    }
    figureName = input.substr(0, input.find("("));
    return figureName;
}
