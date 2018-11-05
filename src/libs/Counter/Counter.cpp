#include"Counter.h"
int Counter::wordCount(std::ifstream &ifStream) {
  unsigned count = 0;
  std::string buf;
  while(!ifStream.eof()) {
    buf = '\0';
    ifStream >> buf;
    if(buf == word)
      count++;
  }
  return count;
}

std::string Counter::resultAsString() {
  return std::to_string(doWithFile([this](std::ifstream &ifStream) {
        return this->wordCount(ifStream);
        }));
}

