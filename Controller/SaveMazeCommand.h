#pragma once


#include "MazeCommand.h"
#include "../Model/MazeModel.h"
#include "ListDirCommand.h"
#include "DisplayMazeCommand.h"

class SaveMazeCommand : public MazeCommand {

public:
    SaveMazeCommand(MazeModel& model) : MazeCommand(model) {}

    void execute(vector<string>& v)
    {
        if (v.size() < 1)
            throw ParametersNumberError();
        _model.saveMaze(v[0], v[1]);
    }
};



