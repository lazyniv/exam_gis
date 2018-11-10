#include <functional>
#include <string>
#include <fstream>
#include <iostream>
#include "lib/Counter/Counter.h"
#include "lib/Hash/Hash.h"
#include "lib/Help/Help.h"
#include "lib/CliDefinition/CliDefinition.h"

int main(int argc, char **argv) {
  CliDefinition parser(argc, argv);
  try {
    parser.parse()->run();
  }
  catch (std::string e) {
    std::cerr << "ERROR: " << e << "\n";
    return 1;
  }
  return 0;
}
