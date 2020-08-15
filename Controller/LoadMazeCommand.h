//
// Created by Lucas Kujawski on 15/08/2020.
//

#pragma once


#include "Command.h"
#include "../Model/MazeModel.h"
#include "ListDirCommand.h"
#include "DisplayMazeCommand.h"
#include "SaveMazeCommand.h"

class LoadMazeCommand : public Command {

    MazeModel&  _model;
public:
    LoadMazeCommand(MazeModel& model) : _model(model) {}

    void execute(vector<string>& v)
    {
        _model.loadMaze(v[0], v[1]);
    }
};



