#include"Hash.h"
unsigned Hash::arrayToInt(char *arr) {
  unsigned result = 0;
  result += (arr[0] << 24);
  result += (arr[1] << 16);
  result += (arr[2] << 8);
  result += arr[3];
  return result;
}

Hash::Hash(std::string fPath): FileAnalyzer(fPath) {}

unsigned Hash::checkSum(std::ifstream &ifStream){
  unsigned result = 0;
  while(!ifStream.eof())
  {
    char buf[] = {0,0,0,0};
    ifStream.read(buf, 4);
    result += arrayToInt(buf);
  }
  return result;
}

std::string Hash::resultAsString() {
  return std::to_string(doWithFile([this](std::ifstream &ifStream){
        return this->checkSum(ifStream);
        }));
}

