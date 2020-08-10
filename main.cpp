#include <iostream>
#include "States/State.h"
#include "Searchers/Searcher.h"
#include "Searchers/BFS.h"
#include "Games/Maze.h"
#include "Searchables/MazeSearchable.h"
#include "MazeGenerator.h"


using namespace std;


int main()
{
    MazeGenerator* mg = new SimpleMazeGenerator();
    Maze m = mg->generate(10);
    MazeSearchable ms(m);

    BFS<pair<int,int>> bfs;

    Solution<pair<int,int>> s = bfs.search(ms);
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