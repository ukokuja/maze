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
#include "../Managers/MemoryManager.h"
#include "../Searchers/BFS.h"

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
        notify( "generate");
    }
    void displayMaze(string& mazeName) //throw(NotFoundError)
    {
        try {
            notify( *_memory.get(mazeName));
        } catch (NotFoundError&) {
            notify( "maze_not_found");
        }

    }
    void saveMaze(string& mazeName, string& fileName) //throw(FileError, NotFoundError)
    {
        MazeCompressor c;
        try {
            Maze* m = _memory.get(mazeName);
            ofstream file("../.storage/" + fileName);
            c.compress(*m, file);
            _disk.set(fileName);
            notify( "saved");
        } catch (NotFoundError&) {
            notify( "maze_not_found");
        }

    }
    void loadMaze(string& fileName, string& mazeName) // throw(FileError)
    {
        MazeCompressor c;
        ifstream file;
        try {
            _disk.get(fileName, file);
        } catch (FileError&) {
            notify( "file_not_found");
        }
        Maze* m = c.extract(file);
        file.close();
        _memory.set(mazeName, *m);
        notify( "loaded");
    }
    void mazeSize(string& mazeName) //throw(NotFoundError)
    {
        try {
            Maze* m = _memory.get(mazeName);
            notify(sizeof(*m));
        } catch (NotFoundError&) {
            notify( "maze_not_found");
        }
    }
    void fileSize(string& fileName)
    {
        ifstream file;
        try {
            _disk.get(fileName, file);
        } catch (FileError&) {
            notify( "file_not_found");
        }
        int size = file.tellg();
        file.close();
        notify(to_string(size) + " bytes");
    }
    void solve(string& mazeName, string& searcher, string heuristic="") //throw(NotFoundError)
    {
        SearcherFactory<pair<int, int>> sf;
        string searcher_heuristic = searcher + heuristic;
        auto s = sf.get(searcher_heuristic);
        Maze* m;
        try {
            m = _memory.get(mazeName);
        } catch (NotFoundError&) {
            notify( "maze_not_found");
        }
        string key = getCacheKey(mazeName);
        try {
            _cache.get(key);
            notify("solved");
        } catch (NotFoundError&) {
            MazeSearchable ms(*m);
            auto solution = s->search(ms);
            string key = getCacheKey(mazeName);
            _cache.set(key, solution);
            notify( "solved");
        }

    }
    void displaySolution(string& mazeName) //throw(NotFoundError)
    {
        try {
            string key = getCacheKey(mazeName);
            notify(_cache.get(key));
        } catch (NotFoundError&) {
            notify("maze_not_found");
        }
    }


    void printSolution(string& mazeName) //throw(NotFoundError)
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
    PersistentMemoryManager<Solution<pair<int, int>>> _cache;

};
