#ifndef FILE_ANALYZER_H
#define FILE_ANALYZER_H
#include<string>
#include<fstream>
#include<functional>
#include"../Command/Command.h"
class FileAnalyzer: public Command {

  protected:
    std::string fPath;
    using CallBack = std::function<int(std::ifstream&)>;
    int doWithFile(CallBack);

  public:
    FileAnalyzer(std::string);
};
#endif
