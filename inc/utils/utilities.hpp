#ifndef UTILITIES_HPP_
#define UTILITIES_HPP_

#include <vector>
#include <algorithm>

template <typename T, typename U, typename Compare>
void RemoveFromVector(std::vector<T>& vec, const U& value, Compare comp) {
    vec.erase(std::remove_if(vec.begin(), vec.end(),
        [&](T& item) {
            return comp(item, value);
        }), vec.end());
}

template<typename T>
std::string default_repr(const std::string& classname, const std::string& name) {
    return "<" + classname + ": " + name + ">";
}

#endif /* UTILITIES_HPP_ */