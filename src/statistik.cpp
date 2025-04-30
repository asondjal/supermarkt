#include "statistik.hpp"

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
uint32_t Statistik::AnzahlDaten() const {
    std::lock_guard<std::mutex> lock(datenMutex_);
    return static_cast<uint32_t>(datenBuffer_.size());
}