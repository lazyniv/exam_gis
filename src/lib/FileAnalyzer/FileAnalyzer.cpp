#include "FileAnalyzer.h"

unsigned FileAnalyzer::doWithFile(CallBack f) {
  std::ifstream ifStream(fPath.c_str());
  if(!ifStream.is_open())
    throw *(new std::string("Can't open file"));

  unsigned result = f(ifStream);

  ifStream.close();
  return result;
}

FileAnalyzer::FileAnalyzer(std::string fPath) {
  this->fPath = fPath;
}

