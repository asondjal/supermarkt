#ifndef LOGGING_HPP_
#define LOGGING_HPP_

#include <fstream>
#include <mutex>
#include <string>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <sstream>

enum class LogLevel { 
    DEBUG,
    INFO,
    WARNING,
    ERROR };

class Logging {
public:
    Logging(const std::string& logFilePath, LogLevel level = LogLevel::INFO, bool consoleOutput = true);
    ~Logging();

    void log(const std::string& message, LogLevel level = LogLevel::INFO);
    void setLevel(LogLevel level);
    void enableConsoleOutput(bool enable);

private:
    std::ofstream logFile_;
    std::mutex logMutex_;
    LogLevel currentLevel_;
    bool consoleOutput_;

    std::string getTimestamp() const;
    std::string levelToString(LogLevel level) const;
};

#endif /* LOGGING_HPP_ */