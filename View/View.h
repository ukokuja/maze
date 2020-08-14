#pragma once

#include <ostream>
#include <istream>

using namespace std;
class View {
protected:
    ostream& _out;
    istream& _in;

public:
    View(ostream& out, istream& in) : _out(out), _in(in){};
    virtual void start()=0;
};