#pragma once
using namespace std;

#include <dirent.h>
#include <string>
#include <vector>
#include <cstdio>
#include <map>
#include <fstream>
#include "Manager.h"
#include "../Games/Maze.h"
template <class T>
class MemoryManager : public Manager<T> {
public:

    virtual void set(string& key, T value) {
        _memory[key] = value;
    }

    virtual T get(string& key) {
        auto instance = _memory.find(key);
        if (instance == _memory.end()) {
            throw NotFoundError();
        }
        return &instance;
    }
private:
    map<string, T> _memory;
};
