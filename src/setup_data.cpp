#include <cstddef>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

template <typename T>
int read_self_data (const std::string file_path, std::vector<std::vector<T>>& self_data, size_t& size) {
  std::ifstream file(file_path);
  if (!file.is_open()) {
    std::cerr << "File does not exist!" <<std::endl;
    return 1;
  }

  std::string line;
  
  while (getline(file, line)) {
    std::vector<T> new_data;
    std::stringstream ss(line);
    std::string number;

    while (getline(ss, number, ',')) {
        std::istringstream(number) >> number;  
        new_data.push_back(number);  
    }
    self_data.push_back(new_data);
  }

  if (self_data.empty()) {
    size = 0;
  } 
  else {
    size = self_data[0].size();
  }
  return 0;
}
