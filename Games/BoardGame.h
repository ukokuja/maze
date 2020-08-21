#pragma  once
#include <string>
#include <ostream>
#include "../Solution.h"
#define OUTER_DELIMITER '|'
#define INNER_DELIMITER ','
using namespace std;
class BoardGame {
public:
    BoardGame (vector<vector<string>>& board, int size) : _board(board), _size(size) {};
public:
    friend ostream& operator<< (ostream& stream, const BoardGame& b) {
        return stream;
    }
    friend istream& operator>> (istream& stream, const BoardGame&b) {
        return stream;
    }

    virtual vector<vector<string>>& getBoard() {
        return _board;
    }

    string getMetaData () {
        return to_string(_size);
    }

    virtual string getData () {
        string s;
        for (int i = 0; i < _size; i++) {
            for (int j = 0; j < _size; j++) {
                s += _board[i][j];
            }
        }
        return s;
    }
    virtual void setData () {
        string s = to_string(_size);
        for (int i = 0; i < _size; i++) {
            for (int j = 0; j < _size; j++) {
                s += _board[i][j] + ",";
            }
        }
    }

protected:
    vector<vector<string>> _board;
    int _size;
public:
    int getSize() const {
        return _size;
    }
    void setBoard(vector<vector<string>>& board) {
        _board = board;
    }

};
