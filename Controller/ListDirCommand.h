
#pragma once
#include "Command.h"
#include "../Model/MazeModel.h"

class ListDirCommand : public Command {

    MazeModel&  _model;
public:
    ListDirCommand(MazeModel& model) : _model(model) {}

    void execute(vector<string>& v)
    {
        _model.getDir();
    }
};
