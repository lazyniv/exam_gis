#ifndef HASH_H
#define HASH_H
#include <string>
#include <fstream>
#include "../FileAnalyzer/FileAnalyzer.h"
class Hash: public FileAnalyzer {

  private:
    unsigned arrayToInt(char *);
    unsigned checkSum(std::ifstream &);

  public:
    Hash(std::string);
    std::string resultAsString() override;
};
#endif

