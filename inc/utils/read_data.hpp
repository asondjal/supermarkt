#ifndef READ_DATA_HPP_
#define READ_DATA_HPP_

#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <mutex>
#include <poppler/cpp/poppler-document.h>
#include <poppler/cpp/poppler-page.h>

class ReadData {
public:
    explicit ReadData(const std::string& path);
    std::mutex& GetMutex();
    std::string ReadFile() const; 
    std::string ReadTxt() const;
    std::string ReadCSV() const;
    std::string ReadJSON() const;
    std::string ReadPDF() const;
    std::string ReadAuto() const; 

private:
    std::string filePath_;
    mutable std::mutex mtx_;
};

#endif /* READ_DATA_HPP_ */