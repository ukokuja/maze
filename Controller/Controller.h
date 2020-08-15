#pragma once

#include <map>
#include <string>
#include <vector>
#include <functional>
#include "Command.h"
#include "../utils.h"

using namespace std;

class Controller
{
public:
    Controller() {}
    ~Controller() {}


public:
    virtual pair<Command*, vector<string>> get(const string& command)
    {
        Utils u;
        vector<string> commandParts;
        u.split(command, commandParts);

        int i;
        string currentCommand;
        auto it = _commands.find(currentCommand);
        pair<Command*, vector<string>> commandParamsCandidate;
        for (i = 0; i < commandParts.size(); i++) {
            currentCommand += commandParts[i];
            it = _commands.find(currentCommand);
            if (it != _commands.end())
                commandParamsCandidate = make_pair(it->second,
                                                   std::vector<string>(commandParts.begin() + i + 1, commandParts.end()));
            currentCommand += delimiter;
        }

        return commandParamsCandidate;
    }
protected:
    map<string, Command*> _commands;
};

