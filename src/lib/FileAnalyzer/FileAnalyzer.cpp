#include"FileAnalyzer.h"

int FileAnalyzer::doWithFile(CallBack f) {
  std::ifstream ifstream(fPath.c_str());
  if(!ifstream.is_open())
    throw "Can't open file";

  int result = f(ifstream);

  ifstream.close();
  return result;
}

FileAnalyzer::FileAnalyzer(std::string fPath) {
  this->fPath = fPath;
}

