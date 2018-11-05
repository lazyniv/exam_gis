#include<string>
#include<fstream>
#include<iostream>
using namespace std;
class Command {
  public:

  void run() {
    std::cout << resultAsString();
  }

  virtual string resultAsString() = 0;
};

class FileAnalyzer : public Command {
protected:
  string fPath;
public:
  FileAnalyzer(std::string fPath) {
    this -> fPath = fPath;
  }
};

class Counter : public FileAnalyzer {
  std::string word;
public:
  Counter(string fPath, string word): FileAnalyzer(fPath) {
    this -> word = word;
  }

  int doWithFile(int (Counter::*f)(std::ifstream&)) {
    std::ifstream ifStream;
    ifStream.open(fPath.c_str());
    if(!ifStream.is_open())
      throw "FIXME";

    int result =(this->*f)(ifStream);

    ifStream.close();
    return result;
  }

  int wordCount(std::ifstream &ifStream) {
    unsigned int count = 0;
    string buf;
    while(!ifStream.eof()) {
      buf = '\0';
      ifStream >> buf;
      if(buf == word)
        count++;
    }
    return count;
  }

  string resultAsString() {
    return std::to_string(doWithFile(&Counter::wordCount));
  }
};

/*class Hash : public FileAnalyzer {

};*/

int main(int argc, char *argv[]) {
  Command *c = new Counter("test/fixtures/input.txt", "world");
  c->run();
  return 0;
}
