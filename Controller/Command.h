#pragma once

class ParametersNumberError : public std::exception {};
class Command
{
public:
    virtual void execute(vector<string>&) = 0;
};
