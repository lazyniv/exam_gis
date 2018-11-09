#include"CliParser.h"
#include<iostream> //FIXME

CliParser::CliParser(int argc, char **argv) {
  this->argc = argc;
  this->argv = argv;
}

std::string CliParser::cmd() {
  return argv[0];
}

void CliParser::parseOpt() {
  int opt = 0;
  std::string optString = "f:m:v:h";
  while(opt != -1) {
    opt = getopt(argc, argv, optString.c_str());
    switch(opt) {
      case 'f':
        fPath = optarg;
        break;
      case 'm':
        mode = optarg;
        break;
      case 'v':
        word = optarg;
        break;
      case 'h':
        help = true;
      case -1: break;
      default: throw(errMessage(""));
     }
  }
}

std::string CliParser::errMessage(std::string mess) {
  return mess + "\n Try `" + cmd() + " -h' for help.";
}

void CliParser::missing(std::string val, std::string mess)
{
  if(val.empty())
    throw errMessage("Missing " + mess);
}

std::string CliParser::usage() {
  return "OPTS:\n\
  -h - show this message\n\
  -m - working mode [checksum|words]\n\
       - <words> counts words in the file\n\
       - <checksum> calculates of the file checksum\n\
  -f - filepath\n\
  -v - word (for <words> mode only)\n";
}

Command *CliParser::parse() {

  parseOpt();

  if(argc < 2)
    throw errMessage("Missing arguments");

  if(help)
    return new Help(this);

  if(mode == "words") {
    missing(word,"word");
    missing(fPath,"path to file");
    return new Counter(fPath,word);
  }
  else if(mode == "checksum") {
    missing(fPath,"path to file");
    return new Hash(fPath);
  }
  else throw errMessage("Invalid mode '" + mode  + "'");

}
