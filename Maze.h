#pragma once
using namespace std;

#include <string>
#include "BoardGame.h"
#include "State.h"
#define WALL 0
#define FREE 2
#define POS 1
class Maze : public BoardGame
{
public:
    Maze(vector<vector<int>> board, int size, State<pair<int,int>> &endPos, State<pair<int,int>> &startPos) : BoardGame(board, size), _endPos(endPos), _startPos(startPos) {};
    ~Maze() {};

public:
    State<pair<int,int>>& getStart() { return _startPos; }
    State<pair<int,int>>& getEnd() { return _endPos; }
    string getData () {
        return BoardGame::getData() + \
            to_string(_startPos.getState().first) + "," +
            to_string(_startPos.getState().second) + "," +
            to_string(_endPos.getState().first) + "," +
            to_string(_endPos.getState().first) + ",";
    }


    vector<State<pair<int,int>>> calculateStates (State<pair<int,int>> &s) {
        int x = s.getState().first;
        int y = s.getState().second;
        vector<State<pair<int,int>>> states;
        checkAndPush(states, State<pair<int,int>>(make_pair(x+1, y), 1, s));
        checkAndPush(states, State<pair<int,int>>(make_pair(x, y-1), 1, s));
        checkAndPush(states, State<pair<int,int>>(make_pair(x-1, y), 1, s));
        checkAndPush(states, State<pair<int,int>>(make_pair(x, y+1), 1, s));


        return states;
    }

private:
    State<pair<int,int>>& _startPos;
    State<pair<int,int>>& _endPos;

    void checkAndPush(vector<State<pair<int, int>>>& vector, const State<pair<int, int>>& s) {
        int x = s.getState().first;
        int y = s.getState().second;
        if (x > -1 && x < _size && y > -1 && y < _size && _board[x][y] == FREE) {
            vector.push_back(s);
        }
    }

};
