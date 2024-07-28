#include "./WebServ/WebServ.hpp"
#include <cstdlib>
#include <exception>
#include <cstring>
#include <iostream>

int main (int argc, char **args)
{
  WebServ *webServ;

  std::cout << "Hello World!" << std::endl;
  try {
    if (argc == 1) webServ = new WebServ(); 
    if (argc == 2) webServ = new WebServ(std::string(args[1])); 
  } catch (std::exception &e) { std::cerr << e.what() << std::endl; exit(EXIT_FAILURE);}
  std::cout << *webServ << std::endl;
  return 0;
}
 



