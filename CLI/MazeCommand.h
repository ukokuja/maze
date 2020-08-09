#pragma once
#include "Command.h"
#include "Model.h"


class ListDirCommand : public Command
{
public:
    ListDirCommand(Model *model) : _model(model) {}
    void execute()
    {
        _model->listDir();
    }
private:
    Model * _model;
};


class GenerateMazeCommand : public Command
{
public:
    GenerateMazeCommand(Model *model) : _model(model) {}
    void execute()
    {
        _model->generate();
    }
private:
    Model * _model;
};

class DisplayMazeCommand : public Command
{
public:
    DisplayMazeCommand(Model *model) : _model(model) {}
    void execute()
    {
        _model->displayMaze();
    }
private:
    Model * _model;
};

class SaveMazeCommand : public Command
{
public:
    SaveMazeCommand(Model *model) : _model(model) {}
    void execute()
    {
        _model->saveMaze();
    }
private:
    Model * _model;
};

class LoadMazeCommand : public Command
{
public:
    LoadMazeCommand(Model *model) : _model(model) {}
    void execute()
    {
        _model->loadMaze();
    }
private:
    Model * _model;
};

class MazeSizeCommand : public Command
{
public:
    MazeSizeCommand(Model *model) : _model(model) {}
    void execute()
    {
        _model->mazeSize();
    }
private:
    Model * _model;
};

class FileSizeCommand : public Command
{
public:
    FileSizeCommand(Model *model) : _model(model) {}
    void execute()
    {
        _model->fileSize();
    }
private:
    Model * _model;
};

class SolveMazeCommand : public Command
{
public:
    SolveMazeCommand(Model *model) : _model(model) {}
    void execute()
    {
        _model->solve();
    }
private:
    Model * _model;
};

class DisplaySolutionCommand : public Command
{
public:
    DisplaySolutionCommand(Model *model) : _model(model) {}
    void execute()
    {
        _model->displaySolution();
    }
private:
    Model * _model;
};

class ExitCommand : public Command
{
public:
    ExitCommand(Model *model) : _model(model) {}
    void execute()
    {
        _model->list();
    }
private:
    Model * _model;
};
