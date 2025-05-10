#include "../inc/utils/statistik.hpp"

Statistik::Statistik() : datenBuffer_{}, datenMutex_{} {}

/**
 * @brief Lädt Daten aus einer Datei in den Datenpuffer
 * @param reader Referenz auf ein ReadData-Objekt
 */
void Statistik::LadeDaten(ReadData& reader) {
    std::string data = reader.ReadFile();
    datenBuffer_.push_back(data);
}

/**
 * @brief Entfernt Daten aus dem Datenpuffer
 * @param data Der zu entfernende Datenwert
 */
void Statistik::EntferneDaten(const std::string& data) {
    std::lock_guard<std::mutex> lock(datenMutex_);
    
    for (auto& bufferData : datenBuffer_) {
        if (bufferData == data) {
            bufferData.clear();
        }
    }

    auto it = std::remove_if(datenBuffer_.begin(), datenBuffer_.end(),
                             [](const std::string& s) {
                                return s.empty();
                             });
    datenBuffer_.erase(it, datenBuffer_.end());
}

/**
 * @brief Berechnet die Anzahl an Elementen im Datenpuffer
 * @return Anzahl der Elemente im Datenpuffer
 */
uint32_t Statistik::ZaehleEintraege() const {
    std::lock_guard<std::mutex> lock(datenMutex_);
    return static_cast<uint32_t>(datenBuffer_.size());
}

/**
 * @brief Berechnet die Anzahl an Zeichen im Datenpuffer
 * @return Anzahl der Zeichen im Datenpuffer
 */
uint32_t Statistik::ZaehleZeichen() const {
    std::lock_guard<std::mutex> lock(datenMutex_);
    uint32_t zeichen = 0;
    for (const auto& data : datenBuffer_) {
        zeichen += static_cast<uint32_t>(data.size());
    }
    return zeichen;
}

/**
 * @brief Berechnet die Anzahl an Zeilen im Datenpuffer
 * @return Anzahl der Zeilen im Datenpuffer
 */
uint32_t Statistik::ZaehleLinien() const {
    std::lock_guard<std::mutex> lock(datenMutex_);
    uint32_t zeilen = 0;
    for (const auto& data : datenBuffer_) {
        if (!data.empty() && data.back() != '\n') {
            ++zeilen;
        }    
        zeilen += std::count(data.begin(), data.end(), '\n');
    }
    return zeilen;
}

uint32_t Statistik::ZaehleVariable(std::string variable) const {
    std::lock_guard<std::mutex> lock(datenMutex_);
    uint32_t anzahl = 0;
    for (const auto& data : datenBuffer_) {
        uint32_t entryCount = 0;
        std::regex variableRegex(R"(\b)" + variable + R"(\b)");
        auto variablesBegin = std::sregex_iterator(data.begin(), data.end(), variableRegex);
        auto variablesEnd = std::sregex_iterator();
        entryCount = std::distance(variablesBegin, variablesEnd);
        anzahl += entryCount;
    }
    return anzahl;
}

/**
 * @brief Berechnet die Anzahl an Wörtern im Datenpuffer (ohne Zahlen)
 * @return Anzahl der Wörter im Datenpuffer
 */
uint32_t Statistik::ZaehleWorte() const {
    std::lock_guard<std::mutex> lock(datenMutex_);
    uint32_t woerter = 0;
    std::regex wordRegex(R"(\b[a-zA-ZäöüÄÖÜß]+\b)");
    for (const auto& data : datenBuffer_) {
        auto wordsBegin = std::sregex_iterator(data.begin(), data.end(), wordRegex);
        auto wordsEnd = std::sregex_iterator();
        woerter += std::distance(wordsBegin, wordsEnd);
    }
    return woerter;
}

/**
 * @brief Berechnet den Mittelwert der Länge der Daten im Datenpuffer
 * @details Ohne Sperrung vom Mutex
 * @return Mittelwert der Daten
 */
float Statistik::MittelwertIntern() const {
    if (datenBuffer_.empty()) {
        return 0.0f;
    }
    std::regex numberRegex(R"(([-+]?\d*\.?\d+))");
    float sum = 0.0f;
    uint32_t count = 0;

    for (const auto& data : datenBuffer_) {
        auto numbersBegin = std::sregex_iterator(data.begin(), data.end(), numberRegex);
        auto numbersEnd = std::sregex_iterator();

        for (auto it = numbersBegin; it != numbersEnd; ++it) {
            try {
                sum += std::stof(it->str());
                ++count;
            } catch (const std::invalid_argument&) {
                continue;
            }
        }
    }
    if (count == 0) {
        return 0.0f;
    }
    
    std::cout << std::fixed << std::setprecision(2);
    return sum / count;
}

/**
 * @brief Berechnet den Mittelwert der Daten im Datenpuffer
 * @details Mit Sperrung vom Mutex
 * @return Mittelwert der Daten
 */
float Statistik::Mittelwert() const {
    std::lock_guard<std::mutex> lock(datenMutex_);
    return MittelwertIntern();
}

/**
 * @brief Berechnet den Median der Daten im Datenpuffer
 * @return Median der Daten
 */
float Statistik::Median() const {
    std::lock_guard<std::mutex> lock(datenMutex_);
    if (datenBuffer_.empty()) {
        return 0.0f;
    }
    std::vector<float> sizes;
    for (const auto& data : datenBuffer_) {
        sizes.push_back(static_cast<float>(data.size()));
    }
    std::sort(sizes.begin(), sizes.end());
    size_t n = sizes.size();
    if (n % 2 == 0) {
        return (sizes[n / 2 - 1] + sizes[n / 2]) / 2.0f;
    } else {
        return sizes[n / 2];
    }    
}

/**
 * @brief Berechnet den Erwartungswert der Daten im Datenpuffer
 * @return Erwartungswert der Daten
 */
float Statistik::Erwartungswert() const {
    std::lock_guard<std::mutex> lock(datenMutex_);
    if (datenBuffer_.empty()) {
        return 0.0f;
    }
    float sum = 0.0f;
    uint32_t count = 0;

    for (const auto& data : datenBuffer_) {
        std::regex numberRegex(R"(([-+]?\d*\.?\d+))");
        auto numbersBegin = std::sregex_iterator(data.begin(), data.end(), numberRegex);
        auto numbersEnd = std::sregex_iterator();

        for (auto it = numbersBegin; it != numbersEnd; ++it) {
            try {
                sum += std::stof(it->str());
                ++count;
            } catch (const std::invalid_argument&) {
                continue;
            }
        }
    }
    if (count == 0) {
        return 0.0f;
    }
    return sum / count;
}

/**
 * @brief Berechnet die Varianz der Daten im Datenpuffer
 * @return Varianz der Daten
 */
float Statistik::Varianz() const {
    if (datenBuffer_.empty()) {
        return 0.0f;
    }
    float mean = MittelwertIntern();
    float sum = 0.0f;
    uint32_t count = 0;

    for (const auto& data : datenBuffer_) {
        std::regex numberRegex(R"(([-+]?\d*\.?\d+))");
        auto numbersBegin = std::sregex_iterator(data.begin(), data.end(), numberRegex);
        auto numbersEnd = std::sregex_iterator();

        for (auto it = numbersBegin; it != numbersEnd; ++it) {
            try {
                float value = std::stof(it->str());
                sum += (value - mean) * (value - mean);
                ++count;
            } catch (const std::invalid_argument&) {
                continue;
            }
        }
    }
    if (count == 0) {
        return 0.0f;
    }
    
    return sum / count;
}

float Statistik::Standardabweichung() const {
    std::lock_guard<std::mutex> lock(datenMutex_);
    return std::sqrt(Varianz());
}