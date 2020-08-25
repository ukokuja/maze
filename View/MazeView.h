#pragma once
#include "View.h"
#include "../Controller/MazeController.h"
#include "../Model/MazeModel.h"
#include "../utils.h"
#include <string>
#include <algorithm>
#define REP "%s"
#define REP_SIZE 2
class MazeView : public View, public Observer{
public:

    MazeView(ostream &out, istream &in, Controller& controller) : View(out, in, controller){
        _messages["generate"] = "Your maze %s was successfully generated";
        _messages["saved"] = "Your maze %s was successfully saved";
        _messages["loaded"] = "Your maze %s was successfully loaded";
        _messages["solved"] = "Your maze %s was successfully solved";
        _messages["maze_size"] = "Your maze uses %s bytes in memory";
        _messages["file_size"] = "Your maze uses %s bytes in disk";
        _messages["maze_not_found"] = "The maze name is incorrect";
        _messages["file_not_found"] = "The file name is incorrect";
    };

    void help(){
        _out<<"\n"
                   "Help:\n"
                   "    dir <path>                                      shows all files in path.\n"
                   "    generate maze <name> <size> <algorithm>         generate a new maze.\n"
                   "    display <name>                                  display specific maze.\n"
                   "    save maze <name> <file name>                    save specific maze to file.\n"
                   "    load maze <file name> <name>                    load specific maze from file.\n"
                   "    maze size <name>                                memory size of specific maze.\n"
                   "    file size <name>                                file size of specific maze.\n"
                   "    solve <name> <algorithm>                        solve the maze with specific algorithm.\n"
                   "    display solution <name>                         shows solution steps.\n"
                   "    print solution <name>                           shows solution board.\n"
                   "    manual                                          shows manual per command.\n"
                   "    exit                                            exit program.\n";
    }
    void manual () {
        _out<<"\n"
              "Help:\n"
              "\033[32m dir <path>\033[0m\n Description: shows all files in path. \n Its parameter can take any value and will return the files in the indicated folder\n\n"
              "\033[32m generate maze <name> <size> <algorithm>\033[0m\n Description: Generates a new maze.\n * <name> can take any alphanumeric value\n * <size> can take any number bigger than 0 \n * <algorithm> can take only values Kruskal or Random \n\n"
              "\033[32m display <name>\033[0m\n Description: Display specific maze.\n Its parameter can take any alphanumeric value. \n\n"
              "\033[32m save maze <name> <file name>\033[0m \n Description: Save specific maze to file in the folder .storage\n Its parameter can take any alphanumeric value. \n\n"
              "\033[32m load maze <file name> <name>\033[0m \n Description: Load specific maze from file to the system.\n Its parameter can take any alphanumeric value. \n\n"
              "\033[32m maze size <name>\033[0m \n Description: It returns the memory size of specific maze.\n Its parameter can take any alphanumeric value.\n\n"
              "\033[32m file size <name>\033[0m \n Description: It returns the file size of specific maze.\n Its parameter can take any alphanumeric value.\n\n"
              "\033[32m solve <name> <algorithm> <heuristic>\033[0m \n Description:   It solve the maze with specific algorithm.\n It will print a message when solution is ready \n \n * <name> can take any alphanumeric value. It should be a pre-generated maze\n * <algorithm> can take only BFS, AStar Manhattan and AStar Euclidean\n\n"
              "\033[32m display solution <name>\033[0m \n Description: It shows solution steps as positions.\n Its parameter can take any alphanumeric value. \n It should indicate a value of a specific solved maze\n\n"
              "\033[32m print solution <name>\033[0m \n Description: shows solution board.\n Its parameter can take any alphanumeric value. \n It should indicate a value of a specific solved maze\n\n";
    }

    virtual void start() {
        string input;
        while (input != "exit")
        {
            help();
            this->_out << ">>";
            getline(this->_in,input);
            if (input == "manual") {
                manual();
                continue;
            }
            auto commandParts = this->_controller.get(input);
            if (nullptr != commandParts.first) {
                try {
                    commandParts.first->execute(commandParts.second);
                } catch (ParametersNumberError&) {
                    _out << "Incorrect parameters" << endl;
                }
            } else if (input != "exit") {
                    _out << "Unsupported Command!" << endl;
            }

        }
        end();
    }
    virtual void end() {
        this->_out << "Bye!!";
    }

    string getMessage(string &key, string name) {
        if (_messages.find(key) != _messages.end()) {
            string message = _messages[key];
            size_t pos = message.find(REP);
            size_t len = REP_SIZE;
            message = message.replace(pos, len, name);
            return message;
        }
        return key;
    }

    string &getMessage(string &key) {
        if (_messages.find(key) != _messages.end())
            return _messages[key];
        return key;
    }

    virtual void update(Observable& o, string& message) {
        _out << getMessage(message) << endl;
    }

    virtual void update(Observable& o, string& message, string&name) {
        _out << getMessage(message, name) << endl;
    }

    virtual void update(Observable& o, const Maze& m) {
        _out << m << endl;
    }

    virtual void update(Observable& o, MazeSolution<pair<int, int>>* solution) {
        for (auto solution : solution->getSolution())
            _out << solution << endl;
    }

    virtual void update(Observable& o, vector<string> list) {
        for (auto data : list)
            _out << data << endl;
    }

    virtual void update(Observable& o, vector<vector<string>>& v) {
        _out << v << endl;
    }

private:
    map<string, string> _messages;
};
