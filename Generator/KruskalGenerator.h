#pragma once
#include "BoardGenerator.h"
#include "DisjointSet.h"
#include <map>
#include <set>
#include <list>
#include <random>

list<pair<int, int>> sums = {{-2, 0}, {0, -2}, {2, 0}, {0, 2}};

class KruskalMazeGenerator : public MazeGenerator {
public:
    virtual const Maze generate (int _size) {
        int size = _size;
        auto board = initMaze(size);
        pair<int, int> start = make_pair(_size * 4, _size * 4);
        pair<int, int> end = make_pair(0, 0);

        DisjointSet<pair<int, int>> sets(size);
        auto edgesList = initEdges(size);
        while (!edgesList.empty()) {
            auto edges = edgesList.back();
            edgesList.pop_back();
            auto x = edges.first;
            auto y = edges.second;
            if (sets.find(x) != sets.find(y)) {
                setStartAndEnd(x, y, start, end);
                if (x.first == y.first) {
                    if (x.second > y.second) {
                        freeTop(board, x);
                    } else {
                        freeBottom(board, x);
                    }
                } else {
                    if (x.first > y.first) {
                        freeLeft(board, x);
                    } else {
                        freeRight(board, x);
                    }
                }
                sets.join(x, y);
            }
        }
        board[start.first][start.second] = START;
        board[end.first][end.second] = END;
        MazeState startState(start);
        MazeState endState(end);
        return Maze(board, size, startState, endState);
    }
private:
    //Intialize every edge in the board
    virtual vector<pair<pair<int, int>, pair<int, int>>>  initEdges (int size) {
        vector<pair<pair<int, int>, pair<int, int>>> edges;
        for (int i = 0; i < size; i+=2) {
            for (int j = 0; j < size; j+=2) {
                for (auto sum : sums) {
                    auto x = make_pair(i,j);
                    auto y  = make_pair(i + sum.first, j + sum.second);
                    if (y.first > -1 &&
                        y.first < size-1 &&
                        y.second > -1 &&
                        y.second < size-1) {
                        edges.push_back(make_pair(x, y));
                    }
                }
            }
        }
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

        shuffle (edges.begin(), edges.end(), std::default_random_engine(seed));
        return edges;
    }

    //Given a position, sets to free the upper cell
    void freeTop(vector<vector<string>> &board, const pair<int, int> &x) {
        board[x.first][x.second - 1] = enc[FREE];
    }
    //Given a position, sets to free the left cell
    void freeLeft(vector<vector<string>> &board, const pair<int, int> &x) {
        board[x.first - 1][x.second] = enc[FREE];
    }
    //Given a position, sets to free the right cell
    void freeRight(vector<vector<string>> &board, const pair<int, int> &x) {
        board[x.first + 1][x.second] = enc[FREE];
    }
    //Given a position, sets to free the bottom cell
    void freeBottom(vector<vector<string>> &board, const pair<int, int> &x) {
        board[x.first][x.second + 1] = enc[FREE];
    }

    //Sets start as a most left top and end as most right bottom
    void setStartAndEnd(const pair<int, int> &x, const pair<int, int> &y, pair<int, int> &start, pair<int, int> &end) {
        if (moreBottomRightThan(x, start)) {
            start = x;
        }
        if (moreBottomRightThan(y, start)) {
            start = y;
        }
        if (!moreBottomRightThan(x, end)) {
            end = x;
        }
        if (!moreBottomRightThan(y, end)) {
            end = y;
        }
    }

    //Returns if first position is more bottom right than the second one
    bool moreBottomRightThan(pair<int, int> x, pair<int, int> y) {
        return x.first + x.second < y.first + y.second;
    }
};
