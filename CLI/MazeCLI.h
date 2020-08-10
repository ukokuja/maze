#pragma once
#include "CLI.h"
#include "MazeController.h"
#include <string>

class MazeCLI : public CLI {
public:

    virtual void start() {
        string input = "";
        Model* model = new Model();
        MazeController * controller = new MazeController(model);

        while (input != "exit")
        {
            _out << ">>";
            _in >> input;

            Command * com = controller->get(input);
            if (nullptr != com)
                com->execute();
            else
                cout << "Unsupported Command!" << endl;
        }
    }
    virtual void end()=0;

};
