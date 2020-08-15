#pragma once
using namespace std;

#include <dirent.h>
#include <string>
#include <vector>
#include <cstdio>
#include <fstream>
#include "Manager.h"
#include "../Games/Maze.h"

class StorageManager  {
public:
    StorageManager() {
        DIR *dir;
        struct dirent *ent;
        if ((dir = opendir ("../Storage/")) != NULL) {
            while ((ent = readdir (dir)) != NULL) {
                _files.push_back(ent->d_name);
            }
            closedir (dir);
        }
    }



    virtual void set(string &fileName) {
        _files.push_back(fileName);
    }

    virtual ifstream* get(string &fileName) {
        ifstream* file;
        file->open (fileName);
        if (!file->is_open()) throw FileError();
        return file;
    }



    virtual vector<string>& list() {
        return _files;
    }
private:
    vector<string> _files;
};