#pragma once
using namespace std;

#include "MemoryManager.h"
#include <uuid/uuid.h>
#include <string>

template <class T>
class PersistentMemoryManager : public MemoryManager<T> {

public:
        void save() {
            int counter = 0;
            for (auto item : this->_memory) {
                ofstream file("../.cache/" + to_string(counter));
                file << item.first << endl;
                file << item.second->serialize();
                file.close();
                counter++;
            }
        }

        void load () {
            auto cache = _disk.list(".cache");
            for (auto filename : cache) {
                if (filename == "." || filename == "..") continue;
                ifstream file("../.cache/" + filename);
                string key;
                getline(file, key);
                string value;
                getline(file, value);
                T* entity = new T(value);
                this->_memory[key] = entity;
            }
        }
private:
    StorageManager _disk;
};
