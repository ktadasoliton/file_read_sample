  // Copyright 2018 Kota Tada

#include "include/config_file_read.h"
#include <unistd.h>
#include <string>

char* GetConfigString(char *section, char *key, char *inifile ) {
  char took_section[512], section_value[512], specified_section[512];
  char buffer[512];
  bool section_found = false;

  FILE *fp;
  if ((fp = fopen(inifile, "r")) == NULL) {
    return '\0';
  }

  snprintf(specified_section, sizeof(specified_section), "[%s]", section);
  char *p = NULL;
  while (fgets(buffer, 512, fp) != NULL) {
    if (buffer[0] == '#') {
      continue;
    }

    if ((p = strchr(buffer, '=')) != NULL) {
      *p = (' ');
    }

    sscanf(buffer, "%s %s", took_section, section_value);
    if (strcmp(took_section, specified_section) == 0) {
      section_found = true;
    } else {
      if (*took_section == '[') {
        section_found = false;
      }
    }

    if (section_found == true) {
      if (strcmp(took_section, key) == 0) {
        fclose(fp);
        return(strdup(section_value));
      }
    }
  }
  fclose(fp);
  return '\0';
}

int main(int argc, char **argv) {
  int opt;
  while ((opt = getopt(argc, argv, "f")) != -1) {
    switch (opt) {
      case 'f':
            GetConfigString("LogFilePath", "log_file_path", argv[2]);
            GetConfigString("LogFileName", "log_file_name", argv[2]);
      break;
    }
  }
}
