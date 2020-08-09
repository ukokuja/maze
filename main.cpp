#include <iostream>
#include "State.h"
#include "Searcher.h"
#include "BFS.h"
#include "EightPuzzelSearchable.h"


using namespace std;

int main()
{
    State a("A");
    State b("B");
    State goal("B");

    if(b == goal)
        cout << "Target State found!" << endl;


    EightPuzzel ep;
    EightPuzzelSearchable eps(ep);

    BFS bfs;

    Solution s = bfs.search(eps);


    cin.get();
    return 0;
}


TestMazeGenerator t;
TestMazeGenerator t2;
AbstractMazeGenerator* a = new SimpleMazeGenerator();
AbstractMazeGenerator* a2 = new MyMazeGenerator();
t.testMazeGenerator(*a);
t2.testMazeGenerator(*a2);