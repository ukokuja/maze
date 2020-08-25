
#pragma once
#include "MazeCommand.h"
#include "../Model/MazeModel.h"

class ListDirCommand : public MazeCommand {

public:
    ListDirCommand(MazeModel& model) : MazeCommand(model) {}

    void execute(vector<string>& v)
    {
        if (v.size() < 1)
            throw ParametersNumberError();
        _model.getDir(v[0]);
    }
};
