#pragma once
using namespace std;

#include <string>
#include <vector>
#include "BoardGame.h"
#include "../States/MazeState.h"
class Maze : public BoardGame
{
public:
    Maze(const Maze& m) : BoardGame(m), _endPos(m._endPos), _startPos(m._startPos){};
    Maze(vector<vector<char>> board, int size, MazeState &endPos, MazeState &startPos) : BoardGame(board, size), _endPos(endPos), _startPos(startPos) {};
    ~Maze() {};

public:
    const MazeState& getStart() const { return _startPos; }
    const MazeState& getEnd() const { return _endPos; }
    string getData () {
        return BoardGame::getData() + \
            to_string(_startPos.getState().first) + "," +
            to_string(_startPos.getState().second) + "," +
            to_string(_endPos.getState().first) + "," +
            to_string(_endPos.getState().first) + ",";
    }


    vector<State<pair<int, int>>> calculateStates (State<pair<int, int>> s) const {
        int x = s.getState().first;
        int y = s.getState().second;
        vector<State<pair<int, int>>> states;
        checkAndPush(states, MazeState(x + 1, y, &s));
        checkAndPush(states, MazeState(x, y - 1, &s));
        checkAndPush(states, MazeState(x - 1, y, &s));
        checkAndPush(states, MazeState(x, y + 1, &s));


        return states;
    }

private:
    MazeState _startPos;
    MazeState _endPos;

    void checkAndPush(vector<State<pair<int, int>>>& vector, const MazeState& state) const {
        int x = state.getState().first;
        int y = state.getState().second;
        if (x > -1 && x < _size && y > -1 && y < _size && _board[x][y] == 0) { //TBC
            vector.push_back(state);
        }
    }

};
