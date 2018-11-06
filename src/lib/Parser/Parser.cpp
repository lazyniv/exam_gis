#include"Parser.h"

Parser::Parser(int argc, char **argv) {
  this->argc = argc;
  this->argv = argv;
}

Command *Parser::parse() {
  return (new Help());
}

