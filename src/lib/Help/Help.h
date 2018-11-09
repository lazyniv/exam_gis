#ifndef HELP_H
#define HELP_H
#include "../Command/Command.h"
#include "../CliParser/CliParser.h"
#include <string>

class CliParser;
class Help: public Command {
  private:
    CliParser *cliParser;

  public:
    std::string resultAsString() override;
    Help(CliParser *);
};
#endif
