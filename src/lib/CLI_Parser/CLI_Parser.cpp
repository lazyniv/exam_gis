#include"CLI_Parser.h"

CLI_Parser::CLI_Parser(int argc, char **argv) {
  this->argc = argc;
  this->argv = argv;
}

std::string CLI_Parser::cmd() {
  return argv[0];
}

std::string CLI_Parser::errMessage(std::string mess) {
  return mess + "\n Try `" + cmd() + " -h' for help.";
}

Command *CLI_Parser::parse() {
  if(argc < 2)
    throw errMessage("Missing arguments");
  return (new Help());
}

