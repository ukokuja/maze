#pragma once
#include <iostream>
#include <vector>
#include "../States/State.h"

using namespace std;
template <class T>
class Solution
{
public:
    Solution(const vector<State<T>>& solution) : _solution(vector<State<T>>(solution)) {};

    Solution() {};

public:
    virtual void setStep (string data, State<T>* prev)=0;
    vector<State<T>> getSolution() {
        return _solution;
    }
    virtual string serialize ()=0;

protected:
    vector<State<T>> _solution;
};

