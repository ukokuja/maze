#pragma once

#include <string>
#include <memory>
using namespace std;

template <class T>
class State
{
public:
    State(T state): _state(state), _cost(0), _cameFrom(nullptr){}
    State(T state, double cost, State<T>& cameFrom): _state(state), _cost(cost), _cameFrom(make_unique<State<T>>(cameFrom)){}
    ~State() {};

public:
    bool operator == (State& s) { return _state.compare(s._state) == 0; }
    T getState() const { return _state; };
    T getCost() const { return _cost; };
    T getCameFrom() const { return _cameFrom; };
    void setCameFrom(State<T> cameFrom) {
        _cameFrom = make_unique(cameFrom);
    }

protected:
    T					    _state;
    double				    _cost;
    unique_ptr<State<T>>    _cameFrom;
};

