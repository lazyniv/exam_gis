#include"Command/Command.h"
#include<fstream>
#include<functional>
class FileAnalyzer: public Command {

  protected:
    std::string fPath;
    using CallBack = std::function<int(std::ifstream&)>;
    int doWithFile(CallBack);

  public:
    FileAnalyzer(std::string);
};

