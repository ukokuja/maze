#pragma once

#include <ostream>
#include <istream>
#include "../Controller/Controller.h"

using namespace std;
class View {
public:
    View(ostream &out, istream &in, Controller& controller) : _out(out), _in(in), _controller(controller) {};
    View(View& v) : _out(v._out), _in(v._in), _controller(v._controller) {};
    virtual void start()=0;

protected:
    ostream& _out;
    istream& _in;
    Controller& _controller;

};