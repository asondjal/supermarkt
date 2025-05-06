#include "../inc/utils/read_data.hpp"

ReadData::ReadData(const std::string& path) : filePath_{path} {}

std::mutex& ReadData::GetMutex() {
    return mtx_;
}

/**
 * @brief Liest den Inhalt einer Datei aus und gibt ihn als String zurück
 * @return Inhalt der Datei als String
 */
std::string ReadData::ReadFile() const {
    std::lock_guard<std::mutex> lock(mtx_); // Schutz vor Race Conditions
    if (!std::filesystem::exists(filePath_)) {
        throw std::runtime_error("File does not exist: " + filePath_);
    }
    std::ifstream file(filePath_);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filePath_);
    }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return content;
}

/**
 * @brief Liest den Inhalt einer Textdatei aus und gibt ihn als String zurück
 * @return Inhalt der Text-Datei als String
 */
std::string ReadData::ReadTxt() const {
    return ReadFile();
}

/**
 * @brief Liest den Inhalt einer CSV-Datei aus und gibt ihn als String zurück
 * @return Inhalt der CSV-Datei als String
 */
std::string ReadData::ReadCSV() const {
    return ReadFile();
}

/**
 * @brief Liest den Inhalt einer JSON-Datei und gibt ihn als String zurück
 * @return Inhalt der JSON-Datei als String
 */
std::string ReadData::ReadJSON() const {
    return ReadFile();
}

/**
 * @brief Liest den Inhalt einer PDF-Datei und gibt ihn als String zurück
 * @return Inhalt der PDF-Datei als String
 */
std::string ReadData::ReadPDF() const {
    std::string content;
    std::lock_guard<std::mutex> lock(mtx_);
    poppler::document* doc = poppler::document::load_from_file(filePath_);
    if (!doc) {
        throw std::runtime_error("Could not open PDF file: " + filePath_);
    }
    for (int i = 0; i < doc->pages(); ++i) {
        poppler::page* p = doc->create_page(i);
        if (p) {
            content += p->text().to_latin1();
            delete p;
        }
    }
    delete doc;
    return content;
}

/**
 * @brief Liest den Inhalt einer Datei basierend auf der Dateiendung aus
 * @return Inhalt der Datei als String
 */
std::string ReadData::ReadAuto() const {
    auto ext = std::filesystem::path(filePath_).extension().string();
    if (ext == ".txt") {
        return ReadTxt();
    } else if (ext == ".csv") {
        return ReadCSV();
    } else if (ext == ".json") {
        return ReadJSON();
    } else if (ext == ".pdf") {
        return ReadPDF();
    } else {
        throw std::runtime_error("Unsupported file format: " + ext);
    }
}