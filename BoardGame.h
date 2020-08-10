#pragma  once
#include <string>
using namespace std;
class BoardGame {
protected:
    vector<vector<int>> _board;
    int _size;
public:
    BoardGame (vector<vector<int>>& board, int size) : _board(board), _size(size) {

    }
    string getData () {
        string s = to_string(_size);
        for (int i = 0; i < _size; i++) {
            for (int j = 0; j < _size; j++) {
                s += to_string(_board[i][j]) + ",";
            }
        }
        return s;
    }
};
