#pragma once

#include <libgeometry/geometry.h>
#include <string>

std::string word_tolower(std::string word);

Figures identify(std::string figure);

void parse_circle(std::string input, mas_figures* circl);

void parse_triangle(std::string input, mas_figures* triang);

std::string parse_name(std::string* input);
