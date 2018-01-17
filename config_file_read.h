  // Copyright 2018 Kota Tada
#ifndef CONFREAD_CONFIGFILEREAD_H_  // NOLINT
#define CONFREAD_CONFIGFILEREAD_H_
class ConfigFileRead {
 public:
  char *GetConfigString(char *section, char *key, char *inifile);
};

#endif  // CONFREAD_CONFIGFILEREAD_H_  //NOLINT
