#pragma once

#include <map>
#include <string>
#include <functional>
#include "Command.h"
#include "Controller.h"
#include "ListDirCommand.h"
#include "DisplayMazeCommand.h"
#include "GenerateMazeCommand.h"
#include "SaveMazeCommand.h"
#include "LoadMazeCommand.h"
#include "MazeSizeCommand.h"
#include "FileSizeCommand.h"
#include "SolveMazeCommand.h"
#include "DisplaySolutionCommand.h"
#include "PrintSolutionCommand.h"


using namespace std;

class MazeController : public Controller
{
public:
    MazeController(MazeModel& model)
    {
        _commands["dir"] = new ListDirCommand(model);
        _commands["generate maze"] = new GenerateMazeCommand(model);
        _commands["display"] = new DisplayMazeCommand(model);
        _commands["save maze"] = new SaveMazeCommand(model);
        _commands["load maze"] = new LoadMazeCommand(model);
        _commands["maze size"] = new MazeSizeCommand(model);
        _commands["file size"] = new FileSizeCommand(model);
        _commands["solve"] = new SolveMazeCommand(model);
        _commands["display solution"] = new DisplaySolutionCommand(model);
        _commands["print solution"] = new PrintSolutionCommand(model);
    }

};

