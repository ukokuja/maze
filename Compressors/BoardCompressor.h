#pragma once

#include <string>
#include "../Games/BoardGame.h"
using namespace std;

class BoardCompressor {
public:
    virtual ofstream& compress(BoardGame& b, ofstream& stream){
        char lastChar = OUTER_DELIMITER;
        int counter = 0;
        auto metadata =  b.getMetaData();
        auto data =  b.getData();
        stream << metadata << OUTER_DELIMITER;
        lastChar = data[0];
        for(char& c : data) {
            if (lastChar == c) {
                counter++;
            } else {
                stream << counter << INNER_DELIMITER << lastChar << OUTER_DELIMITER;
                counter = 1;
            }
            lastChar = c;
        }
        stream << counter << INNER_DELIMITER << lastChar << OUTER_DELIMITER;
        return stream;
    };
    virtual BoardGame* extract(ifstream& stream) {
        string line;
        getline(stream, line, OUTER_DELIMITER);
        int size = stoi(line);
        vector<vector<string>> board = vector<vector<string>>(size);
        int current = 0;
        while (current < size * size) {
            getline(stream, line, OUTER_DELIMITER);
            int n = stoi(line.substr(0, line.find(INNER_DELIMITER)));
            char c = line.back();
            for (int i = current; i < current + n; i++) {
                if (!(i%size)) board[i/size] = vector<string>(size);
                board[i/size][i%size] = c;
            }
            current += n;
        }
        cout << board << endl;
        return new BoardGame(board, size);
    }
};
