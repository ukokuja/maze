#pragma once

#include <map>
#include <string>
#include <functional>
#include "Command.h"
#include "MazeCommand.h"
#include "../utils.h"


using namespace std;

class Controller
{
public:
    Controller() {}
    ~Controller() {}


public:
    virtual Command * get(const string& command)
    {
        auto commandParts = Utils::split(command);
        string currentCommand = commandParts[0];
        auto it = _commands.find(currentCommand);
        auto itCandidate = _commands.find(currentCommand);
        for (int i = 1; i < commandParts.size(); i++) {
            currentCommand += " " + commandParts[i];
            it = _commands.find(currentCommand);
            if (it != _commands.end())
                itCandidate = it;

        }

        if (itCandidate == _commands.end())
            return nullptr;

        return itCandidate->second;
    }
protected:
    map<string, Command*> _commands;
};

