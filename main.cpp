#include <iostream>
//#include "States/State.h"
//#include "Searchers/Searcher.h"
//#include "Searchers/BFS.h"
//#include "Searchers/AStar.h"
//#include "Games/Maze.h"
//#include "Searchables/MazeSearchable.h"
//#include "Generator/BoardGenerator.h"
//#include "Generator/KruskalGenerator.h"
//#include "Generator/TestMazeGenerator.h"
#include "Model/MazeModel.h"
#include "Controller/MazeController.h"
#include "View/MazeView.h"
#include "Searchers/ManhattanHeuristic.h"
#include "Searchers/EuclideanHeuristic.h"
#include "Generator/TestMazeGenerator.h"


using namespace std;



int main()
{
    srand (time(0));
   /*
    TestMazeGenerator t;
    TestMazeGenerator t2;
    BoardGenerator* a = new KruskalMazeGenerator();
    BoardGenerator* b = new RandomGenerator();
    t.testMazeGenerator(*a);
    t.testMazeGenerator(*b);
    */

    MazeModel model;
    MazeController controller(model);

    MazeView view(cout, cin, controller);
    model.addObserver(view);

//    string mazeName = "lucas";
//    string loadedMazeName = "gal";
//    string algoName = "Random";
//    string searcher = "AStar";
//    string heuristic = "Manhattan";
//    model.generate(mazeName, 20, algoName);
//    model.displayMaze(mazeName);
//    string filename = "ra.txt";
//    model.saveMaze(mazeName, filename);
//    model.loadMaze(filename, loadedMazeName);
//    model.solve(mazeName, searcher, heuristic);
//    model.printMazeSolution(loadedMazeName);
//    model.displayMazeSolution(mazeName);


        view.start();

//    BoardGenerator* mg = new KruskalMazeGenerator();
//    Maze m = mg->generate(5);
//    m.print();
//    MazeSearchable ms(m);

//    BFS<pair<int,int>> bfs;

//    MazeSolution<pair<int,int>> s = bfs.search(ms);
//    m.print(s);

//    Heuristic<pair<int,int>>* h = new EuclideanHeuristic<pair<int,int>>();
//    AStar<pair<int,int>>* astar = new AStar<pair<int,int>>(*h);
//    cout << m << endl;
//    MazeSolution<pair<int,int>> s = astar->search(ms);
    return 0;
}
//
//
