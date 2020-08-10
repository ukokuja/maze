#pragma once
#include <iostream>
#include "Maze.h"
#include "State.h"
#include "MazeSearchable.h"
#include "SearchableGenerator.h"
#include "MazeGenerator.h"
using namespace std;
class TestMazeGenerator {
public:
    TestMazeGenerator() {

    }
    void testMazeGenerator (MazeGenerator &mg) {
        cout << mg.measureAlgorithmTime(/**/) << endl;
        Maze maze = mg.generate(/**/);

        State<pair<int,int>>& s = maze.getStart();

        cout << s << endl;

        vector<State<pair<int,int>>> states = maze.calculateStates();

        for (auto state : states) {
            cout << state._state << endl;
        }

        cout << maze.getEnd() << endl;

        cout << maze << endl;

    }
};
