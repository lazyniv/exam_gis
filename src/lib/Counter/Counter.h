#ifndef COUNTER_H
#define COUNTER_H
#include<string>
#include<fstream>
#include"../FileAnalyzer/FileAnalyzer.h"
class Counter: public FileAnalyzer {

  private:
    std::string word;

  public:
    Counter(std::string, std::string);
    int wordCount(std::ifstream &);
    std::string resultAsString();
};
#endif

