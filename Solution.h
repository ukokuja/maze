#pragma once
#include <iostream>
#include <vector>
#include "States/State.h"
#include "States/MazeState.h"

using namespace std;
template <class T>
class Solution
{
public:
    Solution(const vector<State<T>>& solution) : _solution(vector<State<T>>(solution)) {};
    Solution(string data) {
        State<T>* step;
        size_t pos = 0;
        std::string token;
        while ((pos = data.find(OUTER_DELIMITER)) != std::string::npos) {
            token = data.substr(0, pos);
            setStep(token, step);
            data.erase(0, pos + 1);
        }
    };
    Solution() {};
    ~Solution() {};

    void setStep (string data, State<T>* prev) {
        int x = stoi(data.substr(0, data.find(INNER_DELIMITER)));
        int y = stoi(data.substr(0, data.find(INNER_DELIMITER)));
        int cost = stod(data.substr(0, data.find(INNER_DELIMITER)));
        MazeState newState(x, y, cost);
        if (prev)
            prev->setCameFrom(newState);
        _solution.push_back(newState);
        prev = &newState;
    }

    vector<State<T>> getSolution() {
        return _solution;
    }

    string serialize () {
        string s;
        State<T>* cameFrom = &_solution.front();
        while (cameFrom) {
            s+= to_string(cameFrom->getState().first) \
                    + INNER_DELIMITER + to_string(cameFrom->getState().second) \
                    + INNER_DELIMITER + to_string(cameFrom->getCost()) \
            + OUTER_DELIMITER;
            cameFrom = cameFrom->getCameFrom();
        }
        return s;
    }



private:
    vector<State<T>> _solution;
};

