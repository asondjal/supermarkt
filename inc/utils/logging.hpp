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

    private:
        std::ofstream logFile_;
        std::mutex logMutex_;
        LogLevel currentLevel_;
        bool consoleOutput_;

        std::string GetTimestamp() const;
        std::string LevelToString(LogLevel level) const;
    
    public:
        Logging(const std::string& logFilePath, LogLevel level = LogLevel::INFO, bool consoleOutput = true);
        ~Logging();

        void Log(const std::string& message, LogLevel level = LogLevel::INFO);
        void SetLevel(LogLevel level);
        void EnableConsoleOutput(bool enable);
        std::string GetLevel();
};

#endif /* LOGGING_HPP_ */