#pragma once
using namespace std;
#include <iostream>
#include "../utils.h"
#include "Model.h"
#include "../Factory/GeneratorFactory.h"
#include "../Factory/SearcherFactory.h"
#include "../Compressors/MazeCompressor.h"
#include "../Managers/StorageManager.h"
#include "../Managers/MemoryManager.h"
#include "../Searchers/BFS.h"

using namespace std;
class MazeModel : public Model, public Observable
{
public:
    void getDir()
    {
        notify(_disk.list());
    }
    void generate(string& mazeName, int size, string& generatorName)
    {
        GeneratorFactory g;
        auto mg = g.get(generatorName);
        Maze m = mg->generate(size);
        _memory.set(mazeName, m);
        notify( "generate");
    }
    void displayMaze(string& mazeName) //throw(NotFoundError)
    {
        notify( *_memory.get(mazeName));
    }
    void saveMaze(string& mazeName, string& fileName) //throw(FileError, NotFoundError)
    {
        MazeCompressor c;
        Maze* m = _memory.get(mazeName);
        ofstream file("../Storage/" + fileName);
        c.compress(*m, file);
        _disk.set(fileName);
        notify( "saved");
    }
    void loadMaze(string& fileName, string& mazeName) // throw(FileError)
    {
        MazeCompressor c;
        ifstream* file = _disk.get(fileName);
        Maze m(*file);
        file->close();
        _memory.set(mazeName, m);
        notify( "loaded");
    }
    void mazeSize(string& mazeName) //throw(NotFoundError)
    {
        Maze* m = _memory.get(mazeName);
        notify(m->getSize()/2);
    }
    void fileSize(string& fileName)
    {
        ifstream* file = _disk.get(fileName);
        int size = file->tellg();
        file->close();
        notify(to_string(size) + " bytes");
    }
    void solve(string& mazeName, string& searcher) //throw(NotFoundError)
    {
        SearcherFactory<pair<int, int>> sf;
        auto s = sf.get(searcher);
        Maze* m = _memory.get(mazeName);
        MazeSearchable ms(*m);
        auto solution = s->search(ms);
        _cache.set(mazeName, solution);
        notify( "solved");
    }
    void displaySolution(string& mazeName) //throw(NotFoundError)
    {
        notify(_cache.get(mazeName));
    }

    void printSolution(string& mazeName) //throw(NotFoundError)
    {
        SearcherFactory<pair<int, int>> sf;
        Maze* m = _memory.get(mazeName);
        auto solution = _cache.get(mazeName);
        m->setSolution(*solution);
        notify(*m);
    }



private:
    MemoryManager<Maze> _memory;
    StorageManager _disk;
    MemoryManager<Solution<pair<int, int>>> _cache;

};
