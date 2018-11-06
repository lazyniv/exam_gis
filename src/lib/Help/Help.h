#ifndef HELP_H
#define HELP_H
#include"../Command/Command.h"
#include<string>
class Help: public Command {
  public:
    std::string resultAsString() override;
};
#endif
