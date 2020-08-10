#pragma once

#include <string>
#include <memory>
using namespace std;

template <class T>
class State
{
public:
    State<T>(T state): _state(state), _cost(0), _cameFrom(nullptr){}

    ~State() {};

public:
    virtual bool operator == (const State& s) const{ return _state == s._state ; }
    T getState() const { return _state; };
    double getCost() const { return _cost; };
    State<T>* getCameFrom() const { return _cameFrom; };
    void setCameFrom(State<T> cameFrom) {
        _cameFrom = &cameFrom;
    }
    bool operator< (const State<T>& b) const {
        return _cost < b.getCost();
    }
    bool operator> (const State<T>& b) const{
        return _cost >= b.getCost();
    }

protected:
    T					    _state;
    double				    _cost;
//    unique_ptr<State<T>>    _cameFrom;
    State<T>*    _cameFrom;
};

