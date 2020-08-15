#pragma once
#include "Command.h"
#include "../Model/MazeModel.h"
#include "ListDirCommand.h"

class DisplayMazeCommand : public Command {

    MazeModel&  _model;
public:
    DisplayMazeCommand(MazeModel& model) : _model(model) {}

    void execute(vector<string>& v)
    {
        _model.displayMaze(v.front());
    }
};
