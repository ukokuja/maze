#pragma once

#include "../Model/MazeModel.h"
#include "Command.h"

class GenerateMazeCommand : public Command
{
public:
    GenerateMazeCommand(MazeModel& model) : _model(model) {}

    void execute(vector<string>& v)
    {
        _model.generate(v[0], stoi(v[1]), v[2]);
    }

private:
    MazeModel&  _model;
};