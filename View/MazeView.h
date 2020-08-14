#pragma once
#include "View.h"
#include "../Controller/MazeController.h"
#include "../Model/MazeModel.h"
#include <string>

class MazeView : public View {
public:

    virtual void start() {
        string input = "";
        MazeModel model;
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
