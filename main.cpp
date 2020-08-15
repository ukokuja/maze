#include <iostream>
//#include "States/State.h"
//#include "Searchers/Searcher.h"
//#include "Searchers/BFS.h"
//#include "Searchers/AStar.h"
//#include "Games/Maze.h"
//#include "Searchables/MazeSearchable.h"
//#include "Generator/MazeGenerator.h"
//#include "Generator/KruskalGenerator.h"
//#include "Generator/TestMazeGenerator.h"
#include "Model/MazeModel.h"
#include "Controller/MazeController.h"
#include "View/MazeView.h"


using namespace std;



int main()
{
    srand (time(0));
//
//    TestMazeGenerator t;
//    MazeGenerator* a = new KruskalMazeGenerator();
//    t.testMazeGenerator(*a);

    MazeModel model;
    MazeController controller(model);

    MazeView view(cout, cin, controller);
    model.addObserver(view);

    view.start();

//    MazeGenerator* mg = new KruskalMazeGenerator();
//    Maze m = mg->generate(5);
//    m.print();
//    MazeSearchable ms(m);
//
//    BFS<pair<int,int>> bfs;
//
//    Solution<pair<int,int>> s = bfs.search(ms);
//    m.print(s);

//    AStar<pair<int,int>> astar;
//
//    Solution<pair<int,int>> s = astar.search(ms);
    return 0;
}
//
//
