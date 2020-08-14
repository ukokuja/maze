#pragma once
#include "Command.h"
#include "../Model/MazeModel.h"


class ListDirCommand : public Command
{
public:
    ListDirCommand(MazeModel& model) : _model(model) {}
    void execute()
    {
        _model.listDir();
    }
private:
    MazeModel&  _model;
};


class GenerateMazeCommand : public Command
{
public:
    GenerateMazeCommand(MazeModel& model) : _model(model) {}
    void execute()
    {
        _model.generate();
    }
private:
    MazeModel&  _model;
};

class DisplayMazeCommand : public Command
{
public:
    DisplayMazeCommand(MazeModel& model) : _model(model) {}
    void execute()
    {
        _model.displayMaze();
    }
private:
    MazeModel&  _model;
};

class SaveMazeCommand : public Command
{
public:
    SaveMazeCommand(MazeModel& model) : _model(model) {}
    void execute()
    {
        _model.saveMaze();
    }
private:
    MazeModel&  _model;
};

class LoadMazeCommand : public Command
{
public:
    LoadMazeCommand(MazeModel& model) : _model(model) {}
    void execute()
    {
        _model.loadMaze();
    }
private:
    MazeModel&  _model;
};

class MazeSizeCommand : public Command
{
public:
    MazeSizeCommand(MazeModel& model) : _model(model) {}
    void execute()
    {
        _model.mazeSize();
    }
private:
    MazeModel&  _model;
};

class FileSizeCommand : public Command
{
public:
    FileSizeCommand(MazeModel& model) : _model(model) {}
    void execute()
    {
        _model.fileSize();
    }
private:
    MazeModel&  _model;
};

class SolveMazeCommand : public Command
{
public:
    SolveMazeCommand(MazeModel& model) : _model(model) {}
    void execute()
    {
        _model.solve();
    }
private:
    MazeModel&  _model;
};

class DisplaySolutionCommand : public Command
{
public:
    DisplaySolutionCommand(MazeModel& model) : _model(model) {}
    void execute()
    {
        _model.displaySolution();
    }
private:
    MazeModel&  _model;
};

class ExitCommand : public Command
{
public:
    ExitCommand(MazeModel& model) : _model(model) {}
    void execute()
    {
        _model.list();
    }
private:
    MazeModel&  _model;
};
