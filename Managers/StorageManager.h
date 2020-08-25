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

    virtual void get(string &fileName, ifstream& file) {
        file.open("../.storage/" + fileName, fstream::in);
        if (!file.is_open()) throw FileError();
    }



    virtual vector<string> list(string _dir) {
        vector<string> files;
        DIR *dir;
        struct dirent *ent;
        if ((dir = opendir (("../" + _dir).c_str())) != NULL) {
            while ((ent = readdir (dir)) != NULL) {
                files.push_back(ent->d_name);
            }
            closedir (dir);
        }
        return files;
    }
};