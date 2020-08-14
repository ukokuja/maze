#pragma once
using namespace std;
#include "../Generator/KruskalGenerator.h"
#include "Factory.h"

class GeneratorFactory : public Factory<MazeGeneratorInterface*> {
public:
    virtual MazeGeneratorInterface* get(string& name) {
        if (name == "Kruskal") {
            MazeGenerator* mg = new KruskalMazeGenerator();
            return mg;
        } else if (name == "SimpleMazeGenerator") {
            MazeGenerator* mg = new SimpleMazeGenerator();
            return mg;
        }
        return nullptr;
    }

};