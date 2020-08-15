#pragma once


#include "Command.h"
#include "../Model/MazeModel.h"
#include "ListDirCommand.h"
#include "DisplayMazeCommand.h"
#include "SaveMazeCommand.h"
#include "LoadMazeCommand.h"
#include "MazeSizeCommand.h"
#include "FileSizeCommand.h"
#include "SolveMazeCommand.h"

class PrintSolutionCommand : public Command {

    MazeModel&  _model;
public:
    PrintSolutionCommand(MazeModel& model) : _model(model) {}

    void execute(vector<string>& v)
    {
        _model.printSolution(v.front());
    }
};



