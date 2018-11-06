#ifndef HASH_H
#define HASH_H
#include<string>
#include<fstream>
#include"../FileAnalyzer/FileAnalyzer.h"
class Hash: public FileAnalyzer {

  private:
    unsigned arrayToInt(char *);

  public:
    Hash(std::string);
    unsigned checkSum(std::ifstream &);
    std::string resultAsString();
};
#endif

