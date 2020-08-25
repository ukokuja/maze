#pragma once
#include "../Model/MazeModel.h"
#include "ListDirCommand.h"
#include "MazeCommand.h"

class DisplayMazeCommand : public MazeCommand {

public:
    DisplayMazeCommand(MazeModel& model) : MazeCommand(model) {}

    void execute(vector<string>& v)
    {
        if (v.size() < 1)
            throw ParametersNumberError();
        _model.displayMaze(v.front());
    }
};
