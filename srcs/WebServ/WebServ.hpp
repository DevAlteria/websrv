#ifndef WEBSERV_HPP
#define WEBSERV_HPP

#include <inttypes.h>
#include <exception>
#include <iostream>
#include <string>

class WebServ {
public:
  WebServ();
  WebServ(const WebServ &);
  WebServ(const std::string configPath);
  WebServ &operator=(const WebServ &);
  ~WebServ();
  
  //Getters && setters
  std::string getConfigPath() const;
  std::string getErrorPath() const;
  uint64_t    getClientBodyMax() const;
  uint64_t    getClientTimeOut() const;
  uint64_t    getServerTimeOut() const;
  bool        getDirectoriListing() const;
  std::string getDirectoriDisplayFile() const;
  bool        getBasicAuthEnable() const;
  std::string getBasicAuthFile() const;
  //Exceptions
  class ConfigNotFound : public std::exception { public: virtual const char* what() const throw() { return "Config Not Found"; } };
  class ConfigPremisionError : public std::exception { public: virtual const char* what() const throw() { return "Config permision error"; } };
  class ConfigError : public std::exception { 
      std::string msg;
    public:
      ConfigError(const std::string& file, const int line, const int col, const std::string& err): msg(std::string("Config error parsing file: \"") \
          + file + std::string("\"in line: ") + std::to_string(line) + std::string(" col: ") \
          + std::to_string(col) +  std::string("\n Error: ") + std::string(err)) {};
      virtual const char* what() const throw() { return msg.c_str(); }
  };
private:
  std::string   _configPath;
  
  std::string   _errorPath; 

  uint64_t      _clientBodyMax;
  uint64_t      _clientTimeOut;
  uint64_t      _serverTimeOut;
  
  bool          _directoryListing;
  std::string   _directoryDisplayFile;
  
  //std::string   _CGICPath;
  //std::string   _CGIHaskelPath;
  
  bool          _BasicAuthEnable;
  std::string   _BasicAuthFile; 

  //Servidores_static
    // -get file from route GET
  //Servidores_cgi_c
    // -exec file from route
    // -upload file POST
    // -edit file POST 
    // -delete file DELETE 
  //Servidores_cgi_haskel
    // -Diagonalize matrix GET
    // -UDB matrix factorization GET
  //Conexiones
};

std::ostream&   operator<<( std::ostream& os, const WebServ& w );

#endif // !WEBSERV_HPP
