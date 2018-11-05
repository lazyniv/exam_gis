#include<string>
#include<fstream>
#include<iostream>
using namespace std;
class Command {
  public:
    virtual void run() = 0;
};

class FileAnalyzer : public Command {
protected:
  string fPath;
  std::ifstream inStream;
public:
  FileAnalyzer(std::string fpath) {
    this -> fPath = fPath;
  }
  virtual void InStreamOpen() = 0;
};

class Counter : public FileAnalyzer {
  std::string word;
public:
  Counter(string word, string fPath): FileAnalyzer(fPath) {
    this -> word = word;
  }

  void InStreamOpen() override {
    inStream.open(fPath.c_str());
    cout<<fPath<<endl;
    if(!inStream.is_open()) {
      std::cout<<"fixme"<<endl;
      throw "FIXME";
     }
  }

  void run() {
    unsigned int count;
    string buf;//FIXME
    InStreamOpen();
    /*while(!inStream.eof()) {
      inStream >> buf;
      cout << buf << endl;
      if(buf == word)
        count++;
    }*/
    std::cout << count;
  }
};

/*class Hash : public FileAnalyzer {

};*/

int main(int argc, char *argv[]) {
  Command *c = new Counter("input.txt", "world");
  c->run();
  return 0;
}
