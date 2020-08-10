#pragma once
#include <iostream>
#include "State.h"
using namespace std;
class MazeState : public State<pair<int,int>>
{
public:
    MazeState(pair<int,int> state) : State<pair<int,int>>(state) {};
    ~MazeState() {};

    double calculateCost(State<pair<int,int>>& targetState){
        return abs(_state.first - targetState.getState().first)
        + abs(_state.second - targetState.getState().second);
    }
    friend ostream& operator<< (ostream& stream, const MazeState& s) {
        stream << "(" << s.getState().first << ", " << s.getState().second << ")";
        return stream;
    }
};

