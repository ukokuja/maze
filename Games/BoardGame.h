#pragma  once
#include <string>
#include <ostream>
using namespace std;
class BoardGame {
public:
    BoardGame (vector<vector<string>>& board, int size) : _board(board), _size(size) {};
    BoardGame(const ifstream& data) {

    }
public:
    virtual vector<vector<string>>& getSolution(Solution<pair<int, int>>& solution)=0;

    friend ostream& operator<< (ostream& stream, const BoardGame& b) {
        return stream;
    }
    friend istream& operator>> (istream& stream, const BoardGame&b) {
        return stream;
    }

    virtual string getData () {
        string s = to_string(_size);
        for (int i = 0; i < _size; i++) {
            for (int j = 0; j < _size; j++) {
                s += _board[i][j] + ",";
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
