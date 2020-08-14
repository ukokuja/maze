#pragma once

#include <map>
#include <string>
#include <functional>
#include "Command.h"
#include "Controller.h"
#include "MazeCommand.h"


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
        _commands["display solution"] = new DisplayMazeCommand(model);
        _commands["exit"] = new ExitCommand(model);

    }

};

