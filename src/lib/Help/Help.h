#ifndef HELP_H
#define HELP_H
#include "../Command/Command.h"
#include "../CliDefinition/CliDefinition.h"
#include <string>

class CliDefinition;
class Help: public Command {

  private:
    CliDefinition *cliParser;

  public:
    std::string resultAsString() override;
    Help(CliDefinition *);
};
#endif
