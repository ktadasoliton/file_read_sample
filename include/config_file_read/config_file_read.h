  // Copyright 2018 Kota Tada
#ifndef CONFREAD_CONFIGFILEREAD_H_  // NOLINT
#define CONFREAD_CONFIGFILEREAD_H_
#include <string>
class ConfigFileRead {
 public:
  std::string GetConfigString(const std::string key, const std::string inifile);
};

#endif  // CONFREAD_CONFIGFILEREAD_H_  //NOLINT
