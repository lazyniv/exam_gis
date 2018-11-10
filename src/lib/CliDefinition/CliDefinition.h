#ifndef PARSER_H
#define PARSER_H
#include"../Counter/Counter.h"
#include"../Hash/Hash.h"
#include"../Help/Help.h"
#include<string>
#include<unistd.h>

class CliDefinition {

  private:
    char **argv;
    int argc;
    std::string fPath;
    std::string word;
    std::string mode;
    bool help = false;
    void parseOpt();
    std::string cmd();
    std::string errMessage(std::string);
    void missing(std::string, std::string);

  public:
    CliDefinition(int, char **);
    Command *parse();
    std::string usage();
};
#endif
