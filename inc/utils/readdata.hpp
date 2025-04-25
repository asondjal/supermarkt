#ifndef READDATA_HPP_
#define READDATA_HPP_

#include <string>
#include <vector>
#include <fstream>

class ReadData {
public:
    explicit ReadData(const std::string& path); // explicit erhöht die Sicherheit im Code
    std::vector<std::string> ReadTxt() const;
    std::vector<std::string> ReadLines() const;
    std::vector<std::string> ReadCSV() const;
    std::vector<std::string> ReadJSON() const;

private:
    std::string filePath_;
};

#endif /* READDATA_HPP_ */
