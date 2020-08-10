#pragma once
#include <iostream>
#include <vector>
#include "States/State.h"

using namespace std;
template <class T>
class Solution
{
public:
    Solution(const vector<State<T>>& solution) : _solution(vector<State<T>>(solution)) {};
    Solution() {};
    ~Solution() {};

private:
    vector<State<T>> _solution;
};

