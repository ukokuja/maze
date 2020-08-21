#pragma once
using namespace std;
#include <chrono>
#include <thread>
#include <string>
#include <vector>
#include "BoardGame.h"
#include "../States/MazeState.h"


class Maze : public BoardGame
{
public:
    Maze(const Maze& m) : BoardGame(m), _endPos(m._endPos), _startPos(m._startPos){};
    Maze(BoardGame& b, MazeState &endPos, MazeState &startPos) : BoardGame(b), _endPos(endPos), _startPos(startPos) {};
    Maze(vector<vector<string>> board, int size, MazeState &endPos, MazeState &startPos) : BoardGame(board, size), _endPos(endPos), _startPos(startPos) {};

public:

     vector<vector<string>> getSolution(Solution<pair<int, int>> solution) {
        vector<vector<string>> _solved(_board);
        for (auto step : solution.getSolution()) {
            _solved[step.getState().first][step.getState().second] = enc[SOLUTION];
        }
        return _solved;
    }

    friend ostream& operator<< (ostream& stream, const Maze& m) {
        stream << m._board;
        return stream;
    }

    friend istream& operator>> (istream& stream, const Maze&b) {
        return stream;
    }

public:
    const MazeState& getStart() const { return _startPos; }
    const MazeState& getEnd() const { return _endPos; }

    string getMetaData () {
        return to_string(_startPos.getState().first) + OUTER_DELIMITER +
               to_string(_startPos.getState().second) + OUTER_DELIMITER +
               to_string(_endPos.getState().first) + OUTER_DELIMITER +
               to_string(_endPos.getState().first) + OUTER_DELIMITER;
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
    void checkAndPush(vector<State<pair<int, int>>>& vector, const MazeState& state) const {
        int x = state.getState().first;
        int y = state.getState().second;
        if (x > -1 && x < _size && y > -1 && y < _size && _board[x][y] != enc[WALL]) { //TBC
            vector.push_back(state);
        }
    }
private:
    MazeState _startPos;
    MazeState _endPos;
};