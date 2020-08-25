#pragma once
using namespace std;
#include "../Generator/KruskalGenerator.h"
#include "../Generator/RandomGenerator.h"
#include "Factory.h"

class GeneratorFactory : public Factory<BoardGenerator*> {
public:
    //Returns a Maze generator by name
    virtual BoardGenerator* get(string& name) {
        if (name == "Kruskal") {
            BoardGenerator* mg = new KruskalMazeGenerator();
            return mg;
        } else if (name == "Random") {
            BoardGenerator* mg = new RandomGenerator();
            return mg;
        }
        return nullptr;
    }

};