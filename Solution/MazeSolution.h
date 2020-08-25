#pragma once
#include <iostream>
#include <vector>
#include "Solution.h"
#include "../States/State.h"
#include "../utils.h"
#include "../States/MazeState.h"

using namespace std;
template <class T>
class MazeSolution : public Solution<T>
{
public:
    MazeSolution(const vector<State<T>>& solution) : Solution<T>(vector<State<T>>(solution)) {};
    MazeSolution(string data) : Solution<T>() {
        State<T>* step;
        size_t pos = 0;
        std::string token;
        while ((pos = data.find(OUTER_DELIMITER)) != std::string::npos) {
            token = data.substr(0, pos);
            setStep(token, step);
            data.erase(0, pos + 1);
        }
    };
    virtual void setStep (string data, State<T>* prev) {
        int x = stoi(data.substr(0, data.find(INNER_DELIMITER)));
        int y = stoi(data.substr(0, data.find(INNER_DELIMITER)));
        int cost = stod(data.substr(0, data.find(INNER_DELIMITER)));
        MazeState newState(x, y, cost);
        if (prev)
            prev->setCameFrom(newState);
        this->_solution.push_back(newState);
        prev = &newState;
    }

    virtual vector<State<T>> getSolution() {
        return this->_solution;
    }

    virtual string serialize () {
        string s;
        State<T>* cameFrom = &this->_solution.front();
        while (cameFrom) {
            s+= to_string(cameFrom->getState().first) \
                    + INNER_DELIMITER + to_string(cameFrom->getState().second) \
                    + INNER_DELIMITER + to_string(cameFrom->getCost()) \
            + OUTER_DELIMITER;
            cameFrom = cameFrom->getCameFrom();
        }
        return s;
    }

};

