#include"FileAnalyzer.h"

int FileAnalyzer::doWithFile(CallBack f) {
  std::ifstream ifstream(fpath.c_str());
  if(!ifstream.is_open())
    throw "fixme";

  int result = f(ifstream);

  ifstream.close();
  return result;
}

FileAnalyzer::FileAnalyzer(std::string fPath) {
  this -> fPath = fPath;
}

