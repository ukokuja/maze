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
    vector<string>& getDir()
    {
        return _disk.list();
    }
    void generate(string& mazeName, int size, string& generatorName)
    {
        GeneratorFactory g;
        auto mg = g.get(generatorName);
        Maze m = mg->generate(size);
        _memory.set(mazeName, m);
        notify( "generate");
    }
    Maze& displayMaze(string& mazeName) //throw(NotFoundError)
    {
        notify( *_memory.get(mazeName));
    }
    void saveMaze(string& mazeName, string& fileName) //throw(FileError, NotFoundError)
    {
        MazeCompressor c;
        Maze* m = _memory.get(mazeName);
        ifstream file(fileName);
        _disk.set(fileName, c.compress(*m, file));
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
    int getMazeSize(string& mazeName) //throw(NotFoundError)
    {
        Maze* m = _memory.get(mazeName);
        return m->getSize();
    }
    int getFileSize(string& fileName)
    {
        ifstream* file = _disk.get(fileName);
        int size = file->tellg();
        file->close();
        return size;
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
    Solution<pair<int, int>>* getSolution(string& mazeName) //throw(NotFoundError)
    {
        return _cache.get(mazeName);
    }



private:
    MemoryManager<Maze> _memory;
    StorageManager _disk;
    MemoryManager<Solution<pair<int, int>>> _cache;

};
