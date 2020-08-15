#pragma once
#include "View.h"
#include "../Controller/MazeController.h"
#include "../Model/MazeModel.h"
#include <string>

class MazeView : public View, public Observer{
public:

    MazeView(ostream &out, istream &in, Controller& controller) : View(out, in, controller){
        _messages["generate"] = "Your maze was successfully generated";
    };

    virtual void start() {
        string input;

        while (input != "exit")
        {
            this->_out << ">>";
            getline(this->_in,input);

            auto commandParts = this->_controller.get(input);
            if (nullptr != commandParts.first)
                commandParts.first->execute(commandParts.second);
            else
                cout << "Unsupported Command!" << endl;
        }
        end();
    }
    virtual void end() {
        this->_out << "Bye!!";
    }

    string &getMessage(string &key) {
        return _messages[key];
    }

    virtual void update(Observable& o, string& message) {
        _out << getMessage(message) << endl;
    }

    virtual void update(Observable& o, const Maze& m) {
        _out << m << endl;
    }

private:
    map<string, string> _messages;
};
