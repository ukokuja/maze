//
// Created by Lucas Kujawski on 15/08/2020.
//

#pragma once


#include "MazeCommand.h"
#include "../Model/MazeModel.h"
#include "ListDirCommand.h"
#include "DisplayMazeCommand.h"
#include "SaveMazeCommand.h"
#include "LoadMazeCommand.h"

class MazeSizeCommand : public MazeCommand {

public:
    MazeSizeCommand(MazeModel& model) : MazeCommand(model) {}

    void execute(vector<string>& v)
    {
        if (v.size() < 1)
            throw ParametersNumberError();
        _model.mazeSize(v.front());
    }
};



