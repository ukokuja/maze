#pragma once

#include "MazeCommand.h"
#include "../Model/MazeModel.h"
#include "ListDirCommand.h"
#include "DisplayMazeCommand.h"
#include "SaveMazeCommand.h"

class LoadMazeCommand : public MazeCommand {

public:
    LoadMazeCommand(MazeModel& model) : MazeCommand(model) {}

    void execute(vector<string>& v)
    {
        if (v.size() < 2)
            throw ParametersNumberError();
        _model.loadMaze(v[0], v[1]);
    }
};



