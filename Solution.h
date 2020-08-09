#pragma once
#include <iostream>
#include <vector>
#include "State.h"

using namespace std;
template <class T>
class Solution
{
public:
    Solution() {};
    ~Solution() {};

private:
    vector<unique_ptr<State<T>>> _solution;
};

