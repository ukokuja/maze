#pragma once
using namespace std;
#include <iostream>
#include "Model.h"
#include "../Factory/GeneratorFactory.h"
#include "../Factory/SearcherFactory.h"
#include "../utils.h"
#include "../Managers/StorageManager.h"
#include "../Managers/MemoryManager.h"
#include "../Searchers/BFS.h"
#include "../Compressors/MazeCompressor.h"
#include "../Observer/Observer.h"
#include "../Observer/Observable.h"

using namespace std;

class MazeModel : public Model, Observable
{
public:
    void listDir()
    {
        notify();
    }
    void generate(string& mazeName, int size, string& generatorName)
    {
        GeneratorFactory g;
        auto mg = g.get(generatorName);
        Maze m = mg->generate(size);
        _memory.set(mazeName, &m);
        notify();
    }
    void displayMaze(string& mazeName) //throw(NotFoundError)
    {
        _memory.get(mazeName);
        notify();
    }
    void saveMaze(string& mazeName, string& fileName) //throw(FileError, NotFoundError)
    {
        MazeCompressor c;
        Maze* m = _memory.get(mazeName);
        _disk.set(c.compress(m), fileName);
        notify();
    }
    void loadMaze(string& fileName, string& mazeName) // throw(FileError)
    {
        MazeCompressor c;
        auto file = _disk.get(fileName);
        Maze m(file);
        file.close();
        _memory.set(mazeName, &m);
        notify();
    }
    void mazeSize(string& mazeName) //throw(NotFoundError)
    {
        Maze* m = _memory.get(mazeName);
        cout << sizeof(*m);
        notify();
    }
    void fileSize(string& fileName)
    {
        auto file = _disk.get(fileName);
        notify();
        file.close();
    }
    void solve(string& mazeName, string& searcher) //throw(NotFoundError)
    {
        SearcherFactory<pair<int, int>> sf;
        auto s = sf.get(searcher);
        Maze* m = _memory.get(mazeName);
        auto solution = s->search(*m);
        _cache.set(mazeName, solution);
        notify();
    }
    void displaySolution(string& mazeName) //throw(NotFoundError)
    {
        _cache.get(mazeName);
        notify();
    }

private:
    MemoryManager<Maze*> _memory;
    StorageManager _disk;
    MemoryManager<Solution<pair<int, int>>*> _cache;
public:

};
