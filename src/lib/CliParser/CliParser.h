#ifndef PARSER_H
#define PARSER_H
#include"../Counter/Counter.h"
#include"../Hash/Hash.h"
#include"../Help/Help.h"
#include<string>
#include<unistd.h>
class CliParser {
  private:
    char **argv;
    int argc;
    std::string fPath; //FIXME
    std::string word;  //FIXME
    std::string mode; //FIXME
    bool help = false;
    void parseOpt();
    std::string cmd();
    std::string errMessage(std::string);
  public:
    CliParser(int, char **);
    Command *parse();
};
#endif
