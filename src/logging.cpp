#include "../inc/utils/logging.hpp"

Logging::Logging(const std::string& logFilePath, LogLevel level, bool consoleOutput)
    : currentLevel_(level), consoleOutput_(consoleOutput) {
    logFile_.open(logFilePath, std::ios::app);
    if (!logFile_.is_open()) {
        std::cerr << "[ERROR] Unable to open log file: " << logFilePath << std::endl;
    }
}

Logging::~Logging() {
    if (logFile_.is_open()) {
        logFile_.close();
    }
}

void Logging::log(const std::string& message, LogLevel level) {
    if (level < currentLevel_) return;

    std::string timestamp = getTimestamp();
    std::string levelStr = levelToString(level);
    std::ostringstream logEntry;
    logEntry << "[" << timestamp << "] [" << levelStr << "] " << message << "\n";

    std::lock_guard<std::mutex> lock(logMutex_);
    if (logFile_.is_open()) {
        logFile_ << logEntry.str();
        logFile_.flush();
    }
    if (consoleOutput_) {
        std::cout << logEntry.str();
    }
}

void Logging::setLevel(LogLevel level) {
    std::lock_guard<std::mutex> lock(logMutex_);
    currentLevel_ = level;
}

void Logging::enableConsoleOutput(bool enable) {
    std::lock_guard<std::mutex> lock(logMutex_);
    consoleOutput_ = enable;
}

std::string Logging::getTimestamp() const {
    auto now = std::chrono::system_clock::now();
    auto itt = std::chrono::system_clock::to_time_t(now);
    std::ostringstream ss;
    ss << std::put_time(std::localtime(&itt), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

std::string Logging::levelToString(LogLevel level) const {
    switch (level) {
        case LogLevel::DEBUG: return "DEBUG";
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}
