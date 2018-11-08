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
  opt = getopt(argc, argv, optString.c_str());
  while(opt != -1) {
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
     // default: FIXME
     }
    opt = getopt(argc, argv, optString.c_str());
  }
}

std::string CliParser::errMessage(std::string mess) {
  return mess + "\n Try `" + cmd() + " -h' for help.";
}

Command *CliParser::parse() {
   parseOpt();
  if(argc < 2)
    throw errMessage("Missing arguments");

  if(help)
    return new Help();
//  if(!fPath.empty()) {
//    if(mode == "words") {
//      if(!word.empty())
//        return new Counter(fPath,word);
//      else throw errMessage("Word is empty"); //FIXME
//    }
//    else if(mode == "checksum")
//      return new Hash(fPath);
//    else throw errMessage("Invalid mode");
//  }
//  else throw errMessage("Path to file is empty"); //FIXME
}
