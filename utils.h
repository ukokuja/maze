#pragma once
using namespace std;

#include <string>
#include <vector>
#include <iostream>


template <typename T>
ostream& operator<<(ostream& output, std::vector<T> const& values)
{
    for (auto const& value : values)
    {
        output << value << std::endl;
    }
    return output;
}

class Utils {
public:


    static vector<string> split (string s, string delimiter=" ") {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        string token;
        vector<string> res;

        while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
            token = s.substr (pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back (token);
        }

        res.push_back (s.substr (pos_start));
        return res;
    }
};