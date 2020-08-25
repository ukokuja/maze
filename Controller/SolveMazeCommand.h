#pragma once


#include "MazeCommand.h"
#include "../Model/MazeModel.h"
#include "ListDirCommand.h"
#include "DisplayMazeCommand.h"
#include "SaveMazeCommand.h"
#include "LoadMazeCommand.h"
#include "MazeSizeCommand.h"
#include "FileSizeCommand.h"

class SolveMazeCommand : public MazeCommand {

public:
    SolveMazeCommand(MazeModel& model) : MazeCommand(model) {}

    void execute(vector<string>& v)
    {
        if (v.size() < 2)
            throw ParametersNumberError();
        string heuristic = v.size() > 2 ? v[2] : "";
        _model.solve(v[0], v[1], heuristic);
    }
};



