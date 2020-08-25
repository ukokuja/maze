#pragma once

#include "../Model/MazeModel.h"
#include "ListDirCommand.h"

class DisplaySolutionCommand : public MazeCommand {

public:
    DisplaySolutionCommand(MazeModel& model) : MazeCommand(model) {}

    void execute(vector<string>& v)
    {
        if (v.size() < 1)
            throw ParametersNumberError();
        _model.displayMazeSolution(v.front());
    }
};



