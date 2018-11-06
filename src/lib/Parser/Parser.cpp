#include"Parser.h"

Parser::Parser(int argc, char **argv) {
  this->argc = argc;
  this->argv = argv;
}

std::string Parser::cmd() {
  return argv[0];
}

std::string Parser::errMessage(std::string mess) {
  return mess + "\n Try `" + cmd() + " -h' for help.";
}

Command *Parser::parse() {
  if(argc < 2)
    throw errMessage("Missing arguments");
  return (new Help());
}

