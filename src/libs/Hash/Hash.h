#include"FileAnalyzer/FileAnalyzer.h"
class Hash: public FileAnalyzer {

  private:
    unsigned arrayToInt(char *);

  public:
    Hash(std::string);
    unsigned checkSum(std::ifstream &);
    std::string resultAsString();
};

