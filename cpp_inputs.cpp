#include <iostream>
#include <limits>
#include "cpp_inputs.hpp"

using std::cin;
using std::cout;

bool is_decimal_str(string input)
{
    int dec = 0;
    int index = 0;
    for (auto ch : input)
    {
        if (ch == '.') { dec++; }
        else if ((ch == '+' || ch == '-') && index == 0);
        else if (!isdigit(ch)) { return false; }
        if (dec > 1) { return false; }
        index++;
    }
    return true;
}

uint64_t get_64int()
{
    string input;
    while(!(cin >> input) || !is_int_str(input))
    {
        cout << "is not a interger\nagain: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return stoul(input);
}

bool is_int_str(string input)
{
    for (auto ch : input)
    {
        if (!isdigit(ch)) { return false; }
    }
    return true;
}

double get_double()
{
    string input;
    while(!(cin >> input) || !is_decimal_str(input))
    {
        cout << "is not double\nagain: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return stod(input);
}

