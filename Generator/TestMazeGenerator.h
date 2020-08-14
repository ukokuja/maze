#pragma once
#include <iostream>
#include "../Games/Maze.h"
#include "../States/State.h"
#include "../Searchables/MazeSearchable.h"
#include "MazeGenerator.h"
using namespace std;
class TestMazeGenerator {
public:
    TestMazeGenerator() {

    }
    void testMazeGenerator (MazeGenerator &mg) {
        int size = 20;
        cout << mg.measureAlgorithmTime(size) << endl;
        Maze maze = mg.generate(size);

        auto s = maze.getStart();

        vector<State<pair<int,int>>> states = maze.calculateStates(s);

        for (auto state : states) {
            cout << state.getState().first << ", " << state.getState().second << endl;
        }

        cout << maze.getEnd() << endl;

        cout << maze << endl;

        MazeSearchable ms(maze);

        BFS<pair<int,int>> bfs;

        Solution<pair<int,int>> sol = bfs.search(ms);
        cout << maze << endl;
        maze.setBoard(maze.getSolution(sol));
        cout << maze << endl;

    }
};
