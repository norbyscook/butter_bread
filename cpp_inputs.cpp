#include "cpp_inputs.hpp"

// get a double from console
double get_double()
{
    string input;
    try
    {
        while(!(cin >> input) || !is_decimal_str(input))
        {
            cout << "is not double\nagain: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return stod(input);
}

// get a 64 bit unsigned int from console
uint64_t get_64int()
{
    string input;
    try
    {
        while(!(cin >> input) || !is_int_str(input))
        {
            cout << "is not a integer\nagain: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return stoul(input);
}

// get a string from console
string get_str()
{
    string input;
    while (!(cin >> input))
    {
        cout << "is not a proper string\nagain: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return input;
}

// check to see if string is decimal
bool is_decimal_str(string input)
{
    if (input.empty())
    {
        throw std::runtime_error("empty argument to is_decimal_str()");
    }
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

// check to see if string is interger
bool is_int_str(string input)
{
    if (input.empty())
    {
        throw std::runtime_error("empty argument to is_int_str()");
    }
    for (auto ch : input)
    {
        if (!isdigit(ch)) { return false; }
    }
    return true;
}
