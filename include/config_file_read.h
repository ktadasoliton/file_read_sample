  // Copyright 2018 Kota Tada
#ifndef CONFREAD_CONFIGFILEREAD_H_  // NOLINT
#define CONFREAD_CONFIGFILEREAD_H_
class ConfigFileRead {
 public:
  char *GetConfigString(const char *section, const char *key, const char *inifile);
};

#endif  // CONFREAD_CONFIGFILEREAD_H_  //NOLINT
