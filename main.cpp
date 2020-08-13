#include <iostream>
#include "States/State.h"
#include "Searchers/Searcher.h"
#include "Searchers/BFS.h"
#include "Searchers/AStar.h"
#include "Games/Maze.h"
#include "Searchables/MazeSearchable.h"
#include "Generator/MazeGenerator.h"
#include "Generator/KruskalGenerator.h"


using namespace std;



int main()
{
    srand (time(0));

    MazeGenerator* mg = new KruskalMazeGenerator();
    Maze m = mg->generate(10);
    m.print();
    MazeSearchable ms(m);

    BFS<pair<int,int>> bfs;

    Solution<pair<int,int>> s = bfs.search(ms);

//    AStar<pair<int,int>> astar;
//
//    Solution<pair<int,int>> s = astar.search(ms);
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