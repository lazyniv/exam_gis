#include<string>
#include<iostream>
#ifndef COMMAND_H
#define COMMAND_H
class Command {

  public:
    void run();
    virtual std::string resultAsString() = 0;
};
#endif

