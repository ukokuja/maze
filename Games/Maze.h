#pragma once
using namespace std;
#include <chrono>
#include <thread>
#include <string>
#include <vector>
#include "BoardGame.h"
#include "../States/MazeState.h"

#define FREE "  "
#define WALL "▉▉"
#define SOLUTION "▓▓"


class Maze : public BoardGame
{
public:
    Maze(const Maze& m) : BoardGame(m), _endPos(m._endPos), _startPos(m._startPos){};
    Maze(const ifstream& data) : BoardGame(data), _endPos(MazeState(0, 0, nullptr)), _startPos(MazeState(0, 0, nullptr)){};
    Maze(vector<vector<string>> board, int size, MazeState &endPos, MazeState &startPos) : BoardGame(board, size), _endPos(endPos), _startPos(startPos) {};

public:
    friend ostream& operator<< (ostream& stream, const Maze& m) {
        stream << "\t";
        for (int j = 0; j <= m.getSize(); j++) {
            stream << WALL;
        }
        stream << endl;
        for (int i = -1; i <= m.getSize(); i++) {
            if (i > -1 && i < m.getSize()) {
                stream << "\t" << WALL;
            }
            m.printRow(i, stream);
        }
        stream << endl;
        return stream;
    }
    friend istream& operator>> (istream& stream, const Maze&b) {
        return stream;
    }

public:
    const MazeState& getStart() const { return _startPos; }
    const MazeState& getEnd() const { return _endPos; }
    virtual string getData () {
        return BoardGame::getData() + \
            to_string(_startPos.getState().first) + "," +
               to_string(_startPos.getState().second) + "," +
               to_string(_endPos.getState().first) + "," +
               to_string(_endPos.getState().first) + ",";
    }
    virtual vector<vector<string>>& getSolution(Solution<pair<int, int>>& solution) {
        for (auto step : solution.getSolution()) {
            _board[step.getState().first][step.getState().second] = SOLUTION;
        }
        return _board;
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
        if (x > -1 && x < _size && y > -1 && y < _size && _board[x][y] != WALL) { //TBC
            vector.push_back(state);
        }
    }
    void printRow(int i, ostream& stream) const {
        if (i < 0 || i >= _size) return;
        for (int j = 0; j < _size; j++) {
            if (_board[i][j] != SOLUTION) {
                stream << _board[i][j];
            } else {
                stream << "\033[32m" << _board[i][j] << "\033[0m";
            }
        }
        stream << endl;
    };
private:
    MazeState _startPos;
    MazeState _endPos;
};