#ifndef PARSER_H
#define PARSER_H
#include"../Counter/Counter.h"
#include"../Hash/Hash.h"
#include"../Help/Help.h"
#include<string>
#include<unistd.h>
class CLI_Parser {
  private:
    char **argv;
    int argc;
    int h;
    Command *parseOpt();
    std::string cmd();
    std::string errMessage(std::string);
  public:
    CLI_Parser(int, char **);
    Command *parse();
};
#endif
