#pragma once


#include "Command.h"
#include "../Model/MazeModel.h"
#include "ListDirCommand.h"
#include "DisplayMazeCommand.h"

class SaveMazeCommand : public Command {

    MazeModel&  _model;
public:
    SaveMazeCommand(MazeModel& model) : _model(model) {}

    void execute(vector<string>& v)
    {
        _model.saveMaze(v[0], v[1]);
    }
};



