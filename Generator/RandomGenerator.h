#pragma once
#include "MazeGenerator.h"
#include "../Factory/SearcherFactory.h"
#include "../utils.h"
#include <map>
#include <set>
#include <list>
#include <random>


class RandomGenerator : public MazeGenerator {
public:

    void fillRandomlyFreePositions(const int& size, vector<vector<string>>& board, Solution<pair<int, int>> solution) const {
        int filled = 0;
        int calc = 0;
        while (filled < size * size / 5  || calc > size * size) {
            calc++;
            auto pos = getRandomPair(size);
            bool isFound = false;
            for (const auto& step : solution.getSolution()) {
                if (pos == step.getState()) {
                    isFound = true;
                    break;
                }
            }
            if (!isFound) {
                board[pos.first][pos.second] = enc[WALL];
                filled++;
            }
        }
    }

    virtual const Maze generate (int size) {
        auto board = initMaze(size);
        pair<int, int> start = make_pair(0, 0);
        pair<int, int> end = make_pair(size -2, size -2);
        MazeState startState(start);
        MazeState endState(end);
        board[start.first][start.second] = START;
        board[end.first][end.second] = END;
        Maze m(board, size, startState, endState);
        SearcherFactory<pair<int, int>> sf;
        bool solved = false;
        while (!solved) {
            try {
                for (int i = 0; i < size * size; i++)
                    setRandomlyFreePositions(size, board, start, end);
                m.setBoard(board);
                MazeSearchable ms(m);
                auto solution = sf.any()->search(ms);
                solved = true;
                fillRandomlyFreePositions(size, board, solution);
                m.setBoard(board);
            } catch (NoSolutionException& e) {
                solved = false;
            }
        }

        return m;
    }

    void setRandomlyFreePositions(int size, vector<vector<string>> &board, const pair<int, int> &start,
                             const pair<int, int> &end) {
        auto pos = getRandomPair(size);
        board[pos.first][pos.second] = enc[FREE];
        board[start.first][start.second] = START;
        board[end.first][end.second] = END;
    }

    pair<int,int> getRandomPair(int size) const {
        random_device rd;
        mt19937 mt(rd());
        uniform_int_distribution<int> uniformDist(0 , (size - 2));
        int x = uniformDist(mt);
        int y = uniformDist(mt);
        while (x < 0 || y < 0 || x >= size || y >= size || ((x + y) % 2 == 0)) {
            x = uniformDist(mt);
            y = uniformDist(mt);
        }
        return make_pair(x, y);
    }

};
