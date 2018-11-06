#include"Counter.h"

Counter::Counter(std::string fPath, std::string word): FileAnalyzer(fPath){
  this->word = word;

}

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

