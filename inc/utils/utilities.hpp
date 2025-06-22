#ifndef INC_UTILS_UTILITIES_HPP_
#define INC_UTILS_UTILITIES_HPP_

#include <algorithm>
#include <string>
#include <vector>

template <typename T>
std::string default_repr(const std::string& classname,
  const std::string& name) {
  return "<" + classname + ": " + name + ">";
}

#endif  // INC_UTILS_UTILITIES_HPP_
