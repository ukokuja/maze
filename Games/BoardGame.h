#pragma  once
#include <string>
using namespace std;
class BoardGame {
protected:
    vector<vector<string>> _board;
    int _size;
public:
    BoardGame (vector<vector<string>>& board, int size) : _board(board), _size(size) {

    }
    string getData () {
        string s = to_string(_size);
        for (int i = 0; i < _size; i++) {
            for (int j = 0; j < _size; j++) {
                s += _board[i][j] + ",";
            }
        }
        return s;
    }
    void setBoard(vector<vector<string>>& board) {
        _board = board;
    }
    void print () {
        cout << "\t";
        for (int j = 0; j <= 2*_size; j++) {
            cout << "▉▉";
        }
        cout << endl;
        for (int i = -1; i <= 2*_size; i++) {
            if (i > -1 && i < 2*_size) {
                cout << "\t▉▉";
            } else {
                continue;
            }
            for (int j = 0; j < 2*_size; j++) {
//
                cout << _board[i][j];

            }

            cout << endl;
        }
        cout << endl;
//        for (int i = 0; i < _size; i++) {
//            for (int j = 0; j < _size; j++) {
//                cout << _board[i][j];
//            }
//            cout << endl;
//        }
    };
};
