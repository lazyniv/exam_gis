#ifndef PARSER_H
#define PARSER_H
#include"../Counter/Counter.h"
#include"../Hash/Hash.h"
#include"../Help/Help.h"

class Parser {
  private:
    char **argv;
    int argc;
    Command *parseOpt();
    std::string cmd();
    std::string errMessage(std::string);
  public:
    Parser(int, char **);
    Command *parse();
};
#endif
