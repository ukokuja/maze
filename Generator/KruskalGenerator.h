#pragma once
#include "MazeGenerator.h"
#include "DisjointSet.h"
#include <map>
#include <set>
#include <list>
#include <random>


class KruskalMazeGenerator : public MazeGenerator {
    list<pair<int, int>> sums = {{-2, 0}, {0, -2}, {2, 0}, {0, 2}};
public:
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

    bool moreBottomRightThan(pair<int, int> x, pair<int, int> y) {
        return x.first + x.second < y.first + y.second;
    }


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
                if ((x.first - y.first) == 0) {
                    if (x.second > y.second) {
                        board[x.first][x.second - 1] = enc[FREE];
                    } else {
                        board[x.first][x.second + 1] = enc[FREE];
                    }
                } else {
                    if (x.first > y.first) {
                        board[x.first - 1][x.second] = enc[FREE];
                    } else {
                        board[x.first + 1][x.second] = enc[FREE];
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
};
