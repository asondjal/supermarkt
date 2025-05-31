#ifndef INC_UTILS_UTILITIES_HPP_
#define INC_UTILS_UTILITIES_HPP_

#include <algorithm>
#include <string>
#include <vector>

template <typename T, typename U, typename Compare>
void RemoveFromVector(std::vector<T>& vec, const U& value, Compare comp) {
  vec.erase(std::remove_if(vec.begin(), vec.end(),
                           [&](T& item) { return comp(item, value); }),
            vec.end());
}

template <typename T>
std::string default_repr(const std::string& classname,
                         const std::string& name) {
  return "<" + classname + ": " + name + ">";
}

#endif  // INC_UTILS_UTILITIES_HPP_
