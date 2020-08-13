#pragma once
#include "MazeGenerator.h"
#include "DisjointSet.h"
#include <map>
#include <set>
#include <list>


class KruskalMazeGenerator : public MazeGenerator {
    list<pair<int, int>> sums = {{-2, 0}, {0, -2}, {2, 0}, {0, 2}};
public:
    virtual vector<pair<pair<int, int>, pair<int, int>>>  initEdges (int size) {
        vector<pair<pair<int, int>, pair<int, int>>> edges;
        for (int i = 0; i < 2*size; i+=2) {
            for (int j = 0; j < 2*size; j+=2) {
                for (auto sum : sums) {
                    auto x = make_pair(i,j);
                    auto y  = make_pair(i + sum.first, j + sum.second);
                    if (y.first > -1 &&
                    y.first < 2*size-1 &&
                    y.second > -1 &&
                    y.second < 2*size-1) {
                        edges.push_back(make_pair(x, y));
//                        cout << "Adds ("<< i << "," << j <<") and ("<<i + sum.first << "," << j + sum.second<< ")" << endl;
                    }
                }
            }
        }
        random_shuffle (edges.begin(), edges.end(), [](int n) { return rand() % n; });
        for (auto edge : edges) {
//            cout << "We have ("<< edge.first << "," << edge.second <<")" << endl;
        }
        return edges;
    }

    virtual const Maze generate (int size) {
        auto board = initMaze(size);
        MazeState start(0, 0, nullptr);
        MazeState end(2*size-1, 2*size-1, nullptr);
        Maze m = Maze(board, size, start, end);
        board[0][0] = "S ";
        board[2*size-2][2*size-2] = " E";
        DisjointSet<pair<int, int>> sets(2*size);
        auto edgesList = initEdges(size);
        while (!edgesList.empty()) {
            auto edges = edgesList.back();
            edgesList.pop_back();
            auto x = edges.first;
            auto y = edges.second;
            if (sets.find(x) != sets.find(y)) {
//                cout << "Merges ("<< x.first << "," << x.second <<") and ("<<y.first << "," << y.second<< ")" << endl;

                m.setBoard(board);
                m.print();
                if ((x.first - y.first) == 0) {
                    if (x.second > y.second) {
//                        cout << "Destroy wall ("<< x.first << "," << x.second - 1 <<")1: " << board[x.first][x.second - 1] <<  endl;
                        board[x.first][x.second - 1] = "  ";
                    } else {
//                        cout << "Destroy wall ("<< x.first << "," << x.second + 1 <<")2: " << board[x.first][x.second - 1] <<  endl;
                        board[x.first][x.second + 1] = "  ";
                    }
                } else {
                    if (x.first > y.first) {
//                        cout << "Destroy wall ("<< x.first - 1<< "," << x.second <<")3: " << board[x.first][x.second - 1] << endl;
                        board[x.first - 1][x.second] = "  ";
                    } else {
//                        cout << "Destroy wall ("<< x.first + 1<< "," << x.second <<")4: " << board[x.first][x.second - 1] <<  endl;
                        board[x.first + 1][x.second] = "  ";
                    }
                }
                sets.join(x, y);
//            } else {
//                cout << "("<< x.first << "," << x.second <<") and ("<<y.first << "," << y.second<< ") are in the same set" << endl;
            }
        }

        return m;

    }
};
