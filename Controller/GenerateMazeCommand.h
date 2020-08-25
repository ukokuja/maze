#pragma once

#include "MazeCommand.h"
#include "../Model/MazeModel.h"

class GenerateMazeCommand : public MazeCommand
{
public:
    GenerateMazeCommand(MazeModel& model)  : MazeCommand(model) {}

    void execute(vector<string>& v)
    {
        if (v.size() < 3)
            throw ParametersNumberError();
        _model.generate(v[0], stoi(v[1]), v[2]);
    }

private:
    MazeModel  _model;
};