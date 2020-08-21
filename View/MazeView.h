#pragma once
#include "View.h"
#include "../Controller/MazeController.h"
#include "../Model/MazeModel.h"
#include <string>
#include "../utils.h"

class MazeView : public View, public Observer{
public:

    MazeView(ostream &out, istream &in, Controller& controller) : View(out, in, controller){
        _messages["generate"] = "Your maze was successfully generated";
        _messages["saved"] = "Your maze was successfully saved";
        _messages["loaded"] = "Your maze was successfully loaded";
        _messages["solved"] = "Your maze was successfully solved";
    };

    void help(){
        _out<<"\n"
                   "Help:\n"
                   "    dir <path>                                  shows all files in path.\n"
                   "    generate maze <name> <size> <algorithm>     generate a new maze.\n"
                   "    display <name>                              display specific maze.\n"
                   "    save maze <name> <file name>                save specific maze to file.\n"
                   "    load maze <file name> <name>                load specific maze from file.\n"
                   "    maze size <name>                            memory size of specific maze.\n"
                   "    file size <name>                            file size of specific maze.\n"
                   "    solve <name> <algorithm>                    solve the maze with specific algorithm.\n"
                   "    display solution <name>                     shows solution steps.\n"
                   "    print solution <name>                       shows solution board.\n"
                   "    exit                                        exit program.\n"
                ;
    }

    virtual void start() {
        string input;
        while (input != "exit")
        {
            help();
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
        if (_messages.find(key) != _messages.end())
            return _messages[key];
        return key;
    }

    virtual void update(Observable& o, string& message) {
        _out << getMessage(message) << endl;
    }

    virtual void update(Observable& o, const Maze& m) {
        _out << m << endl;
    }

    virtual void update(Observable& o, Solution<pair<int, int>>* solution) {
        for (auto solution : solution->getSolution())
            _out << solution << endl;
    }

    virtual void update(Observable& o, vector<string> list) {
        for (auto data : list)
            _out << data << endl;
    }

    virtual void update(Observable& o, int n) {
        _out << n << endl;
    }

    virtual void update(Observable& o, vector<vector<string>>& v) {
        _out << v << endl;
    }

private:
    map<string, string> _messages;
};
