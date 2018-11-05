#include<functional>
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
  using CallBack = std::function<int(std::ifstream&)>;

  int doWithFile(CallBack f) {
    std::ifstream ifStream;
    ifStream.open(fPath.c_str());
    if(!ifStream.is_open())
      throw "FIXME";

    int result = f(ifStream);

    ifStream.close();
    return result;
  }
public:
  FileAnalyzer(std::string fPath) {
    this -> fPath = fPath;
  }
};

class Counter : public FileAnalyzer {
  std::string word;
public:
  Counter(string fPath, string word): FileAnalyzer(fPath) {
    this->word = word;
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
    return std::to_string(doWithFile([this](std::ifstream &ifStream){
            return this->wordCount(ifStream);
          }));
  }
};

class Hash: public FileAnalyzer {
  private:
    unsigned int arrayToInt(char *arr)
    {
      unsigned result = 0;
      result += (arr[0] << 24);
      result += (arr[1] << 16);
      result += (arr[2] << 8);
      result += arr[3];
      return result;
    }
  public:
    Hash(string fPath): FileAnalyzer(fPath) {}

    unsigned int checkSum(std::ifstream &ifStream){
      unsigned int result = 0;
      while(!ifStream.eof())
      {
        char buf[] = {0,0,0,0};
        ifStream.read(buf, 4);
        result += arrayToInt(buf);
      }
      return result;
    }

    string resultAsString() {
      return std::to_string(doWithFile([this](std::ifstream &ifStream){
              return this->checkSum(ifStream);
            }));
    }
};

class Help: public Command {
  string resultAsString() {
    return "FIXME: реализовать";
  }
};

int main(int argc, char *argv[]) {
  Command *c1 = new Counter("test/fixtures/input.txt", "world");
  c1->run();
  cout << endl << endl;
  Command *c2 = new Hash("test/fixtures/input.bin");
  c2->run();
  return 0;
}
