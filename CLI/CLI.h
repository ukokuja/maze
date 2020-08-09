#pragma once

#include <ostream>
#include <istream>

using namespace std;
class CLI {
protected:
    ostream& _out;
    istream& _in;

public:
    CLI(ostream& out, istream& in) : _out(out), _in(in){};
    virtual void start()=0;
};