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

#endif /* UTILITIES_HPP_ */