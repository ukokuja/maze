#pragma once
using namespace std;

#include <string>
#include "BoardGame.h"
#include "State.h"
class Maze : public BoardGame
{
public:
    Maze(int** board, int size, State<int**> &endPos, State<int**> &startPos) : BoardGame(board, size), _endPos(endPos), _startPos(startPos) {};
    ~Maze() {};

public:
    State<int**>& getStart() { return _startPos; }
    State<int**>& getEnd() { return _endPos; }
    string getData () {
        return BoardGame::getData() + "\n" + _startPos.getState() + "," + _startPos.getState();
    }
    vector<State<int**>> calculateStates () {

    }

private:
    State<int**>& _startPos;
    State<int**>& _endPos;
};
