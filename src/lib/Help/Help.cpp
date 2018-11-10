#include "Help.h"

Help::Help(CliDefinition *p) {
  this->cliParser = p;
}

std::string Help::resultAsString() {
  return "cool cli program Usage:\n" + cliParser->usage();
}
