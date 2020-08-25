#pragma once

#include <string>
#include "../Games/BoardGame.h"
using namespace std;

class BoardCompressor {
public:

    //Compress board and adds metadata
    virtual ostream& compress(BoardGame& b, ostream& stream){
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
                writeCharAndCounter(stream, lastChar, counter);
                counter = 1;
            }
            lastChar = c;
        }
        writeCharAndCounter(stream, lastChar, counter);
        return stream;
    }

    // Extracts boardgame and metadata
    virtual BoardGame* extract(istream& stream) {
        string line;
        getline(stream, line, OUTER_DELIMITER);
        int size = stoi(line);
        vector<vector<string>> board = vector<vector<string>>(size);
        int current = 0;
        while (current < size * size) {
            getline(stream, line, OUTER_DELIMITER);
            int repetitionsCount = stoi(line.substr(0, line.find(INNER_DELIMITER)));
            char c = line.back();
            //Iterates it as vector but fills it as matrix
            for (int i = current; i < current + repetitionsCount; i++) {
                if (!(i%size)) board[i/size] = vector<string>(size);
                board[i/size][i%size] = c;
            }
            current += repetitionsCount;
        }
        return new BoardGame(board, size);
    }

private:
    void writeCharAndCounter(ostream &stream, char lastChar, int counter) const {
        stream << counter << INNER_DELIMITER << lastChar << OUTER_DELIMITER;
    };


};
