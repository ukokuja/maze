#pragma once


#include "Command.h"
#include "../Model/MazeModel.h"
#include "ListDirCommand.h"
#include "DisplayMazeCommand.h"
#include "SaveMazeCommand.h"
#include "LoadMazeCommand.h"
#include "MazeSizeCommand.h"

class FileSizeCommand : public Command {

    MazeModel&  _model;
public:
    FileSizeCommand(MazeModel& model) : _model(model) {}

    void execute(vector<string>& v)
    {
        _model.fileSize(v.front());
    }
};



