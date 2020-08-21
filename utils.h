#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define delimiter " "

#define FREE " "
#define WALL "▉"
#define SOLUTION "▓"
#define START "S"
#define END "E"
map<string, string> rep = {{" ", FREE}, {"X", WALL}, {"Y", SOLUTION}, {START, START}, {END, END}};
map<string, string> enc = {{FREE, " "}, {WALL, "X"}, {SOLUTION, "Y"}, {START, START}, {END, END}};

void printRow(vector<string>const& v, int i, ostream& stream) {
    for (int j = 0; j < v.size(); j++) {
        if (rep[v[j]] != SOLUTION) {
            stream << rep[v[j]] << rep[v[j]];
        } else {
            stream << "\033[32m" << rep[v[j]] << rep[v[j]] << "\033[0m";
        }
    }
    stream << endl;
};

ostream& operator<< (ostream& stream, vector<vector<string>>const& v) {
    stream << "\t";
    for (int j = 0; j <= v.size(); j++) {
        stream << WALL << WALL;
    }
    stream << endl;
    int i = 0;
    for (auto r : v) {
        stream << "\t"  << WALL << WALL;
        printRow(v[i], i, stream);
        i++;
    }
    return stream;
}

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