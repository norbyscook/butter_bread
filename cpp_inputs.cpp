#include "cpp_inputs.hpp"

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

