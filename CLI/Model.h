#pragma once

#include <iostream>
using namespace std;

class Model
{
public:
    void listDir(string mazeName)
    {
        cout << "The light is on\n";
    }
    void generate(string mazeName, string generatorName)
    {
        MazeGenerator* mg = new KruskalMazeGenerator();
        Maze m = mg->generate(10);
        cout << "Your maze is ready\n";
    }
    void displayMaze(string mazeName)
    {

        cout << "The light is on\n";
    }
    void saveMaze(string mazeName, string fileName)
    {



        MazeSearchable ms(m);

        BFS<pair<int,int>> bfs;

        Solution<pair<int,int>> s = bfs.search(ms);
        cout << "The light is on\n";
    }
    void loadMaze(string fileName, string mazeName)
    {

        cout << "The light is on\n";
    }
    void mazeSize(string mazeName)
    {

        cout << "The light is on\n";
    }
    void fileSize(string mazeName)
    {
        cout << "The light is on\n";
    }
    void solve(string mazeName, string algorithm)
    {
        cout << "The light is on\n";
    }
    void displaySolution(string mazeName)
    {
        cout << "The light is on\n";
    }
    

};
