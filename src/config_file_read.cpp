  // Copyright 2018 Kota Tada

#include "config_file_read/config_file_read.h"
#include <unistd.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

std::string GetConfigString(const std::string key, const std::string inifile) {
  std::string line_buffer, key_line;
  std::vector<std::string> line_value;
  bool section_found = false;

  std::ifstream ifs(inifile);
  if (ifs.fail()) {
    return "";
  }

  while (std::getline(ifs, line_buffer)) {
    if (buffer[0] == '#') {
      continue;
    }

    std::istringstream iss(line_buffer);
    std::string::size_type index = 0;
    index = line_buffer.find("=");

    if (index != std::string::npos) {
      while (std::getline(iss, key_line, '=')) {
        line_value.push_back(key_line);
      }
      for (int i=0; i < line_value.size(); i++) {
        if (line_value[i] == key) {
          return line_value[i+1];
        }
      }
    }
  }

  ifs.close();
  return "";
}

int main(int argc, char **argv) {
  int opt;
  std::string val;
  while ((opt = getopt(argc, argv, "f")) != -1) {
    switch (opt) {
      case 'f':
            val = GetConfigString("log_file_path", argv[2]);
            printf("path = %s\n", val.c_str());
            val = GetConfigString("log_file_name", argv[2]);
            printf("name = %s\n", val.c_str());
      break;
    }
  }
}
