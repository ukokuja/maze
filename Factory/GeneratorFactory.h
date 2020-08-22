#pragma once
using namespace std;
#include "../Generator/KruskalGenerator.h"
#include "Factory.h"
#include "../Generator/RandomGenerator.h"

class GeneratorFactory : public Factory<MazeGeneratorInterface*> {
public:
    virtual MazeGeneratorInterface* get(string& name) {
        if (name == "Kruskal") {
            MazeGenerator* mg = new KruskalMazeGenerator();
            return mg;
        } else if (name == "Random") {
            MazeGenerator* mg = new RandomGenerator();
            return mg;
        }
        return nullptr;
    }

};