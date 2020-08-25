#pragma once


#include "MazeCommand.h"
#include "../Model/MazeModel.h"
#include "ListDirCommand.h"
#include "DisplayMazeCommand.h"
#include "SaveMazeCommand.h"
#include "LoadMazeCommand.h"
#include "MazeSizeCommand.h"
#include "FileSizeCommand.h"
#include "SolveMazeCommand.h"

class PrintSolutionCommand : public MazeCommand {

public:
    PrintSolutionCommand(MazeModel& model) : MazeCommand(model) {}

    void execute(vector<string>& v)
    {
        if (v.size() < 1)
            throw ParametersNumberError();
        _model.printMazeSolution(v.front());
    }
};



