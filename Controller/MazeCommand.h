#pragma once

#include "Command.h"
#include "../Model/MazeModel.h"

class MazeCommand : public Command {
public:
    MazeCommand(MazeModel& model) : _model(model) {}

protected:
    MazeModel&  _model;
};

