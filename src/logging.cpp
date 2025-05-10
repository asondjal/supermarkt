#include "../inc/utils/logging.hpp" //Tests have to be done!!

/**
 * @brief Konstruktor der Klasse Logging
 * @param logFilePath, level, consoleOutput
 */
Logging::Logging(const std::string& logFilePath, LogLevel level, bool consoleOutput)
    : currentLevel_(level), consoleOutput_(consoleOutput) {
    logFile_.open(logFilePath, std::ios::app);
    if (!logFile_.is_open()) {
        std::cerr << "[ERROR] Unable to open log file: " << logFilePath << std::endl;
    }
}
/**
 * @brief Destruktor der Klasse Logging zum Schließen vom Log-File
 */
Logging::~Logging() {
    if (logFile_.is_open()) {
        logFile_.close();
    }
}

/**
 * @brief Einschreiben von Status-Informationen in die Log-Datei
 * @param message, level
 */
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

/**
 * @brief Setzen der Statusmeldung
 * @param
 */
void Logging::setLevel(LogLevel level) {
    std::lock_guard<std::mutex> lock(logMutex_);
    currentLevel_ = level;
}

/**
 * @brief Setzen der Ausgabe der Konsole
 * @param enable
 */
void Logging::enableConsoleOutput(bool enable) {
    std::lock_guard<std::mutex> lock(logMutex_);
    consoleOutput_ = enable;
}

/**
 * @brief Wiedergabe der Zeit
 * @return Zeitangabe im Format `TT:MM:YY H:M:S`
 */
std::string Logging::getTimestamp() const {
    auto now = std::chrono::system_clock::now();
    auto itt = std::chrono::system_clock::to_time_t(now);
    std::ostringstream ss;
    ss << std::put_time(std::localtime(&itt), "%d.%m.%Y %H:%M:%S");
    return ss.str();
}

/**
 * @brief Konvertierung eines Status in einen String
 * @param level
 * @return Wiedergabe vom Status als String im Format Upper-Case
 */
std::string Logging::levelToString(LogLevel level) const {
    switch (level) {
        case LogLevel::DEBUG: 
        return "DEBUG";
        case LogLevel::INFO: 
        return "INFO";
        case LogLevel::WARNING: 
        return "WARNING";
        case LogLevel::ERROR: 
        return "ERROR";
        default: 
        return "UNKNOWN";
    }
}

/**
 * @brief Wiedergabe vom Level als String
 * @return Status als String
 */
std::string Logging::getLevel() {
    std::lock_guard<std::mutex> lock(logMutex_);
    return levelToString(currentLevel_);
}