#pragma once
#include "State.h"
class MazeState : public State<int**>
{
public:
    MazeState(int** state) : State<int**>(state) {};
    ~MazeState() {};

    double calculateCost(State<int**>& targetState){}//TO-DO COST calculation
};

