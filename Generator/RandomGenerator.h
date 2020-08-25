#pragma once
#include "BoardGenerator.h"
#include "../Factory/SearcherFactory.h"
#include "../utils.h"
#include <map>
#include <set>
#include <list>
#include <random>


class RandomGenerator : public MazeGenerator {
public:
    virtual const Maze generate (int size) {
        auto board = initEmptyMaze(size);
        pair<int, int> start = make_pair(0, 0);
        pair<int, int> end = make_pair(size -2, size -2);
        MazeState startState(start);
        MazeState endState(end);
        board[start.first][start.second] = START;
        board[end.first][end.second] = END;
        Maze m(board, size, startState, endState);
        vector<State<pair<int,int>>> solutionSteps = {startState};
        auto solutionStep = startState;
        while (solutionStep != endState) {
            auto randomPair = getRandomPair(size-2, solutionStep.getState());
            State<pair<int,int>> step(randomPair);
            step.setCameFrom(solutionStep);
            solutionSteps.push_back(step);
            solutionStep = step;
        }
        endState.setCameFrom(solutionStep);
        solutionSteps.push_back(endState);
        MazeSolution<pair<int,int>> solution(solutionSteps);
        fillRandomlyFreePositions(size, board, solution);
        m.setBoard(board);
        return m;
    }
private:

    //It generates random positions and fill the board with them
    void fillRandomlyFreePositions(const int& size, vector<vector<string>>& board, MazeSolution<pair<int, int>> solution) const {
        int row = 0;
        while (row < size) {
            for (int i = 0; i < 1.3 * size; i++) {
                int r = getRandomInt(size-2);
                pair<int,int> pos = make_pair(r, row);
                if (i%2) {
                    pos = make_pair(row, r);
                }
                bool isFound = false;
                for (const auto& step : solution.getSolution()) {
                    if (pos == step.getState()) {
                        isFound = true;
                        break;
                    }
                }
                if (!isFound) {
                    board[pos.first][pos.second] = enc[WALL];
                }
            }
            row+=2;
        }
    }

    //Return a random number greater than zero and lower than the size
    int getRandomInt(int size) const {
        random_device rd;
        mt19937 mt(rd());
        uniform_int_distribution<int> uniformDist(0 , size);
        return uniformDist(mt);
    }

    // Returns a random pair that is closest to the end than the previous step
    pair<int,int> getRandomPair(int size, pair<int,int> prev) const {
        random_device rd;
        mt19937 mt(rd());
        uniform_int_distribution<int> uniformDist(0 , 1);
        if (prev.first == size) {
            prev.second++;
        } else if (prev.second == size) {
            prev.first++;
        } else {
            if (uniformDist(mt)) {
                prev.first++;
            } else {
                prev.second++;
            }
        }
        return prev;
    }

};

