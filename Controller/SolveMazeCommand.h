//
// Created by Lucas Kujawski on 15/08/2020.
//

#pragma once


#include "Command.h"
#include "../Model/MazeModel.h"
#include "ListDirCommand.h"
#include "DisplayMazeCommand.h"
#include "SaveMazeCommand.h"
#include "LoadMazeCommand.h"
#include "MazeSizeCommand.h"
#include "FileSizeCommand.h"

class SolveMazeCommand : public Command {

    MazeModel&  _model;
public:
    SolveMazeCommand(MazeModel& model) : _model(model) {}

    void execute(vector<string>& v)
    {
        string heuristic = v.size() > 2 ? v[2] : "";
        _model.solve(v[0], v[1], heuristic);
    }
};



