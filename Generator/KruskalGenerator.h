#pragma once
#include "MazeGenerator.h"
#include "DisjointSet.h"
#include <map>


class KruskalMazeGenerator : public MazeGenerator {
    map<pair<pair<int, int>, pair<int, int>>, const char> dir;
public:
    virtual vector<pair<pair<int, int>, pair<int, int>>>  initEdges (int size) {
        vector<pair<pair<int, int>, pair<int, int>>> edges;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    for (int l = 0; l < size; l++) {
                        if (k != i && l != j) {
                            edges.push_back(make_pair(make_pair(k, l), make_pair(i, j)));
                            if (rand() % 2) {
                                dir.emplace(make_pair(make_pair(k, l), make_pair(i, j)), '#');
                            } else {
//                            cout << "["<< i<x<"]" << "["<< j<<"]=" << "W" << endl;
                                dir.emplace(make_pair(make_pair(k, l), make_pair(i, j)), '~');
                            }
                        }
                    }
                }
            }
        }
        random_shuffle (edges.begin(), edges.end(), [](int n) { return rand() % n; });
        return edges;
    }

    virtual const Maze generate (int size) {
        auto board = initMaze(size);
        DisjointSet<pair<int, int>> sets(size);
        int i = 0;
        auto edges = initEdges(size);
        while (!edges.empty()) {
            auto edge = edges.back();
            edges.pop_back();
            auto x = edge.first;
            auto y = edge.second;
            board[y.first][y.second] = dir.find(make_pair(x, y))->second;
            if (sets.find(x) != sets.find(y)) {
                sets.join(x, y);
            }
        }
        MazeState start(0, 0, nullptr);
        MazeState end(size-1, size-1, nullptr);
        for (i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << board[i][j];
            }
            cout << endl;
            for (int j = 0; j < size; j++) {
                if (i < size - 1 && board[i][j] == board[i+1][j])
                    cout << "_";
                else cout << " ";
            }
            cout << endl;
        }
        return Maze(board, size, start, end);
    }
};
