#ifndef INC_UTILS_READ_DATA_HPP_
#define INC_UTILS_READ_DATA_HPP_

#include <poppler/cpp/poppler-document.h>
#include <poppler/cpp/poppler-page.h>

#include <filesystem>
#include <fstream>
#include <mutex>
#include <string>
#include <vector>

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

#endif  // INC_UTILS_READ_DATA_HPP_
