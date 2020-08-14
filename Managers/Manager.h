#pragma once
#include <string>
using namespace std;
class FileError : public exception {};
class NotFoundError : public exception{};
template <class T>
class Manager {

    virtual void set(string& key, T value)=0;
    virtual T get(string& key)=0;
};
