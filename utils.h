#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define delimiter " "
template <typename T>
ostream& operator<<(ostream& output, vector<T> const& values)
{
    for (auto const& value : values)
    {
        output << value << endl;
    }
    return output;
}

class Utils {
public:


    void split(string const &str,
                  vector<string> &out)
    {
        size_t start;
        size_t end = 0;

        while ((start = str.find_first_not_of(delimiter, end)) != string::npos)
        {
            end = str.find(delimiter, start);
            out.push_back(str.substr(start, end - start));
        }
    }

};