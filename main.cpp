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
#include "Searchers/ManhattanHeuristic.h"
#include "Searchers/EuclideanHeuristic.h"


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
    string mazeName = "lucas";
    string loadedMazeName = "gal";
    string algoName = "Kruskal";
    string searcher = "AStar";
    string heuristic = "Manhattan";
//    model.generate(mazeName, 20, algoName);
//    model.displayMaze(mazeName);
    string filename = "a.txt";
//    model.saveMaze(mazeName, filename);
    model.loadMaze(filename, loadedMazeName);
    model.solve(loadedMazeName, searcher, heuristic);
    model.printSolution(loadedMazeName);

    //    view.start();

//    MazeGenerator* mg = new KruskalMazeGenerator();
//    Maze m = mg->generate(5);
//    m.print();
//    MazeSearchable ms(m);

//    BFS<pair<int,int>> bfs;

//    Solution<pair<int,int>> s = bfs.search(ms);
//    m.print(s);

//    Heuristic<pair<int,int>>* h = new EuclideanHeuristic<pair<int,int>>();
//    AStar<pair<int,int>>* astar = new AStar<pair<int,int>>(*h);
//    cout << m << endl;
//    Solution<pair<int,int>> s = astar->search(ms);
    return 0;
}
//
//
