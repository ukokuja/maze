#pragma  once
#include <string>
using namespace std;
class BoardGame {
    int** _board;
    int _n;
public:
    BoardGame (int** board, int n) : _board(board), _n(n) {

    }
    string getData () {
        string s;
        for (int i = 0; i < _n; i++) {
            for (int j = 0; j < _n; j++) {
                s += to_string(j) + ",";
            }
        }
        return s;
    }
};
