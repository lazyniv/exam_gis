#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include <iostream>

class Command {

  public:
    void run();
    virtual std::string resultAsString() = 0;
};
#endif

