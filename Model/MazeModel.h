#pragma once
using namespace std;
#include <iostream>
#include <sstream>
#include "../utils.h"
#include "Model.h"
#include "../Factory/GeneratorFactory.h"
#include "../Factory/SearcherFactory.h"
#include "../Compressors/MazeCompressor.h"
#include "../Managers/StorageManager.h"
#include "../Managers/PersistentMemoryManager.h"
#include "../Searchers/BFS.h"
#include "../Managers/MemoryManager.h"

using namespace std;
class MazeModel : public Model, public Observable {
public:
    MazeModel () {
        _cache.load();
    }

    ~MazeModel () {
        _cache.save();
    }

public:
    void getDir(string& dir)
    {
        notify(_disk.list(dir));
    }
    void generate(string& mazeName, int size, string& generatorName)
    {
        GeneratorFactory g;
        auto mg = g.get(generatorName);
        Maze m = mg->generate(size);
        _memory.set(mazeName, m);
        notify( "generate", mazeName);
    }
    void displayMaze(string& mazeName)
    {
        try {
            notify( *_memory.get(mazeName));
        } catch (NotFoundError&) {
            notify( "maze_not_found");
        }

    }
    void saveMaze(string& mazeName, string& fileName) 
    {
        MazeCompressor c;
        try {
            Maze* m = _memory.get(mazeName);
            ofstream file("../.storage/" + fileName);
            c.compress(*m, file);
            notify( "saved", mazeName);
        } catch (NotFoundError&) {
            notify( "maze_not_found");
        }

    }
    void loadMaze(string& fileName, string& mazeName) 
    {
        MazeCompressor c;
        ifstream file;
        try {
            _disk.get(fileName, file);
        } catch (FileError&) {
            notify( "file_not_found");
            return;
        }
        Maze* m = c.extract(file);
        file.close();
        _memory.set(mazeName, *m);
        notify( "loaded", mazeName);
    }
    void mazeSize(string& mazeName)
    {
        try {
            Maze* m = _memory.get(mazeName);
            int count = sizeof(m->getStart());
            count += sizeof(m->getEnd());
            count += sizeof(m->getSize());
            count += m->getSize() * m->getSize() * sizeof(string);
            notify("maze_size", to_string(count));
        } catch (NotFoundError&) {
            notify( "maze_not_found");
        }
    }
    void fileSize(string& mazeName)
    {
        MazeCompressor c;
        try {
            Maze* m = _memory.get(mazeName);
            ostringstream stream;
            c.compress(*m, stream);
            int size = stream.str().size();
            notify("file_size",  to_string(size)+ " bytes");
        } catch (NotFoundError&) {
            notify("maze_not_found");
        }
    }
    void solve(string& mazeName, string& searcher, string heuristic="")
    {
        SearcherFactory<pair<int, int>> sf;
        string searcher_heuristic = searcher + heuristic;
        auto s = sf.get(searcher_heuristic);
        Maze* m;
        try {
            m = _memory.get(mazeName);
        } catch (NotFoundError&) {
            notify( "maze_not_found");
            return;
        }
        string key = getCacheKey(mazeName);
        try {
            _cache.get(key);
            notify("solved", mazeName);
        } catch (NotFoundError&) {
            MazeSearchable ms(*m);
            auto solution = s->search(ms);
            string key = getCacheKey(mazeName);
            _cache.set(key, solution);
            notify( "solved", mazeName);
        }

    }
    void displayMazeSolution(string& mazeName)
    {
        try {
            string key = getCacheKey(mazeName);
            notify(_cache.get(key));
        } catch (NotFoundError&) {
            notify("maze_not_found");
        }
    }
    void printMazeSolution(string& mazeName)
    {
        try {
            Maze* m = _memory.get(mazeName);
            string key = getCacheKey(mazeName);
            auto solution = _cache.get(key);
            vector<vector<string>> solvedBoard = m->getSolution(*solution);
            notify(solvedBoard);
        } catch (NotFoundError&) {
            notify("maze_not_found");
        }

    }

private:
    string getCacheKey(string &mazeName) {
        Maze* m = _memory.get(mazeName);
        ostringstream stream;
        MazeCompressor c;
        c.compress(*m, stream);
        string key = stream.str();
        return key;
    }
private:
    MemoryManager<Maze> _memory;
    StorageManager _disk;
    PersistentMemoryManager<MazeSolution<pair<int, int>>> _cache;

};
