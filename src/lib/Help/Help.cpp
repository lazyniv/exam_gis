#include"Help.h"

Help:: Help(CliParser *p) {
  this->cliParser = p;
}

std::string Help::resultAsString() {

return "cool cli program Usage:\n" + cliParser->usage();
}
