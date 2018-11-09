#ifndef COUNTER_H
#define COUNTER_H
#include <string>
#include <fstream>
#include "../FileAnalyzer/FileAnalyzer.h"

class Counter: public FileAnalyzer {

  private:
    std::string word;
    unsigned wordCount(std::ifstream &);

  public:
    Counter(std::string, std::string);
    std::string resultAsString();
};
#endif

