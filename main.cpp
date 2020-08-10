#include <iostream>
#include "State.h"
#include "Searcher.h"
#include "BFS.h"
#include "Maze.h"
#include "MazeSearchable.h"
#include "MazeGenerator.h"


using namespace std;

int main()
{
    MazeGenerator* mg = new SimpleMazeGenerator();
    Maze* m = mg->generate(10);
    MazeSearchable ms(*m);

    BFS<pair<int,int>>* bfs;

    Solution<pair<int,int>> s = bfs->search(ms);


    cin.get();
    return 0;
}
//
//
//TestMazeGenerator t;
//TestMazeGenerator t2;
//AbstractMazeGenerator* a = new SimpleMazeGenerator();
//AbstractMazeGenerator* a2 = new MyMazeGenerator();
//t.testMazeGenerator(*a);
//t2.testMazeGenerator(*a2);