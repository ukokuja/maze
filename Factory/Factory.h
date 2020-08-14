#pragma once
#include <string>
using namespace std;
template <class T>
class Factory {
public:
    virtual T get(string& name)=0;

};
