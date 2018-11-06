#ifndef PARSER_H
#define PARSER_H
#include"../Counter/Counter.h"
#include"../Hash/Hash.h"
#include"../Help/Help.h"

class Parser {
  private:
    char **argv;
    int argc;
  public:
    Parser(int, char **);
    Command *parse();
};
#endif
