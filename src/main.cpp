#include<functional>
#include<string>
#include<fstream>
#include<iostream>
#include"lib/Counter/Counter.h"
#include"lib/Hash/Hash.h"
#include"lib/Help/Help.h"
#include"lib/Parser/Parser.h"
int main(int argc, char **argv) {
  Parser parser(argc, argv);
  try {
    parser.parse()->run();
  } catch (std::string e) {
    std::cerr << "ERROR: " << e << "\n";
    return 1;
  }
  return 0;
//  Command *c1 = new Counter("test/fixtures/input.txt", "world");
//  c1->run();
//  std::cout << "\n\n";
//  Command *c2 = new Hash("test/fixtures/input.bin");
//  c2->run();
}
