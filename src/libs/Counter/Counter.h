#include"FileAnalyzer/FileAnalyzer.h"
class Counter: public FileAnalyzer {

  private:
    std::string word;

  public:
    int wordCount(std::ifstream &i);
    std::string resultAsString();
};

