#pragma once

#include <string>
#include <memory>

using namespace std;

template<class T>
class State {
public:

    State<T>(T state) : _state(state), _cost(0), _cameFrom(nullptr) {}
    ~State() {};

public:
    T getState() const { return _state; };

    double getCost() const { return _cost; };

    State<T> *getCameFrom() const { return _cameFrom; };

    void setCameFrom(const State<T>& cameFrom) {
        _cameFrom = new State<T>(cameFrom);
    }

public:
    virtual bool operator==(const State &s) const {
        return _state.first == s._state.first && _state.second == s._state.second;
    }

    bool operator<(const State<T> &b) const {
        return _cost < b.getCost();
    }

    bool operator>(const State<T> &b) const {
        return _cost > b.getCost();
    }

protected:
    T _state;
    double _cost;
    State<T> *_cameFrom;
};

