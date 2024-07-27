#include "./WebServ.hpp"

std::ostream&   operator<<( std::ostream& os, const WebServ& w )
{
  return os << "--WebServer " << &w << " --\n\n" << \
    "_configPath:    " << w.getConfigPath() << "\n\n" << \

    "_errorPath:     " << w.getErrorPath() << "\n\n" << \

    "_clientBodyMax: " << w.getClientBodyMax() << "\n" << \
    "_clientTimeOut: " << w.getClientTimeOut() << "\n" << \
    "_serverTimeOut: " << w.getServerTimeOut() << "\n\n" << \

    "_directoryListing:     " << (w.getDirectoriListing() ? "true" : "false") << "\n" << \
    "_directoryDisplayFile: " << w.getDirectoriDisplayFile() << "\n\n" << \

    "_BasicAuthEnable:      " << (w.getBasicAuthEnable() ? "true" : "false") << "\n" << \
    "_BasicAuthFile:        " << w.getBasicAuthFile() << "\n" << std::endl;
}

WebServ::WebServ()
{
  this->_configPath = "./configDefault.webserv";
  
  this->_errorPath = "./errorPagesDefault/";

  this->_clientBodyMax = 65566;
  this->_clientTimeOut = 60000;
  this->_serverTimeOut = 60000;
  
  this->_directoryListing = false;
  this->_directoryDisplayFile = "./directoryTemplateDefault.html";

  this->_BasicAuthEnable = false;
  this->_BasicAuthFile = "./basicAuth";
}

WebServ::WebServ(const WebServ &other)
{
  *this = other;
}

WebServ::WebServ(const std::string configPath) : WebServ() 
{
  this->_configPath = configPath;
}

WebServ &WebServ::operator=(const WebServ &other)
{
  if (this == &other)
    return (*this);
  this->_configPath = other._configPath;
  this->_errorPath = other._errorPath;
  this->_clientBodyMax = other._clientBodyMax;
  this->_clientTimeOut = other._clientTimeOut;
  this->_serverTimeOut = other._serverTimeOut;
  this->_directoryListing = other._directoryListing;
  this->_directoryDisplayFile = other._directoryDisplayFile;
  this->_BasicAuthEnable = other._BasicAuthEnable;
  this->_BasicAuthFile = other._BasicAuthFile;
  return (*this);
}

WebServ::~WebServ()
{

}
