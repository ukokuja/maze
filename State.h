#pragma once

#include <string>
#include <memory>
using namespace std;

template <class T>
class State
{
public:
    State(T state): _state(state), _cost(0), _cameFrom(nullptr){}
    ~State() {};

public:
    bool operator == (State& s) { return _state.compare(s._state) == 0; }
    T getState() { return _state; };
private:
    T					_state;
    double				_cost;
    unique_ptr<State>	_cameFrom;
};

