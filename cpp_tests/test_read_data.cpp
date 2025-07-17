#include "tests/test_read_data.hpp"

void TestReadData() {
  ReadData error_file{"Error_File.sdtxt"};

  try {
    error_file.ReadAuto();
    assert(false && "Exception durch unbekannten Dateitypen");
  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  try {
    error_file.ReadFile();
    assert(false && "Exception durch nicht existente Datei");
  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  ReadData error_pdf{"Dummy.pdf"};
  try {
    error_pdf.ReadPDF();
    assert(false && "Exception durch nicht existente PDF");
  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  ReadData dummyfile{"./data/empty.txt"};
  std::string dummy = dummyfile.ReadTxt();
  assert(dummy != ".");

  std::ifstream empty_file("./data/empty.txt");
  std::string empty_content((std::istreambuf_iterator<char>(empty_file)),
                            std::istreambuf_iterator<char>());
  assert(dummy == empty_content);

  ReadData inventur{"./data/supermarkt_1/produkte.txt"};
  std::string data = inventur.ReadTxt();
  std::ifstream produkt_file("./data/supermarkt_1/produkte.txt");
  std::string data_content((std::istreambuf_iterator<char>(produkt_file)),
                           std::istreambuf_iterator<char>());
  assert(data == data_content);

  ReadData kunden{"./data/supermarkt_0/kunden.txt"};
  std::string kundenData = kunden.ReadTxt();
  std::ifstream kunden_file("./data/supermarkt_0/kunden.txt");
  std::string kunden_content((std::istreambuf_iterator<char>(kunden_file)),
                             std::istreambuf_iterator<char>());
  assert(kundenData == kunden_content);

  ReadData verkaeufer{"./data/supermarkt_0/haendler.txt"};
  std::string verkaeuferData = verkaeufer.ReadTxt();
  std::ifstream verkaeufer_file("./data/supermarkt_0/haendler.txt");
  std::string verkaeufer_content((std::istreambuf_iterator<char>(verkaeufer_file)),
                                 std::istreambuf_iterator<char>());
  assert(verkaeuferData == verkaeufer_content);

  ReadData warenkoerbe{"./data/supermarkt_1/warenkoerbe.txt"};
  std::string warenkoerbeData = warenkoerbe.ReadTxt();
  std::ifstream warenkoerbe_file("./data/supermarkt_1/warenkoerbe.txt");
  std::string warenkoerbe_content((std::istreambuf_iterator<char>(warenkoerbe_file)),
                                  std::istreambuf_iterator<char>());
  assert(warenkoerbeData == warenkoerbe_content);

  ReadData empty_json{"./data/empty.json"};
  std::string empty_json_data = empty_json.ReadJSON();
  assert(empty_json_data != "!");

  std::ifstream empty_json_file("./data/empty.json");
  std::string empty_json_content((std::istreambuf_iterator<char>(empty_json_file)),
                                 std::istreambuf_iterator<char>());
  assert(empty_json_data == empty_json_content);

  ReadData settings{"./.vscode/settings.json"};
  std::string settingsData = settings.ReadJSON();
  std::ifstream settings_file("./.vscode/settings.json");
  std::string settings_content((std::istreambuf_iterator<char>(settings_file)),
                               std::istreambuf_iterator<char>());
  assert(settingsData == settings_content);

  ReadData empty_csv{"./data/empty.csv"};
  std::string empty_csv_data = empty_csv.ReadCSV();
  assert(empty_csv_data == "");
  std::ifstream empty_csv_file("./data/empty.csv");
  std::string empty_csv_content((std::istreambuf_iterator<char>(empty_csv_file)),
                                std::istreambuf_iterator<char>());
  assert(empty_csv_data == empty_csv_content);

  ReadData numbers{"./data/numbers.csv"};
  std::string numbersData = numbers.ReadCSV();
  std::ifstream numbers_file("./data/numbers.csv");
  std::string numbers_content((std::istreambuf_iterator<char>(numbers_file)),
                              std::istreambuf_iterator<char>());
  assert(numbersData == numbers_content);

  ReadData simple_pdf{"README.pdf"};
  std::string simple_pdf_data = simple_pdf.ReadPDF();
  assert(simple_pdf_data != "!");
  std::string simple_pdf_content;
  poppler::document* document = poppler::document::load_from_file("README.pdf");

  if (!document) {
    throw std::runtime_error("Could not open PDF file: README.pdf");
  }
  for (int i = 0; i < document->pages(); ++i) {
    poppler::page* p = document->create_page(i);
    if (p) {
      simple_pdf_content += p->text().to_latin1();
      delete p;
    }
  }
  delete document;

  assert(simple_pdf_data == simple_pdf_content);

  ReadData pdf{"supermarkt.pdf"};
  std::string pdfData = pdf.ReadPDF();
  std::ifstream pdf_file("supermarkt.pdf");
  std::string pdf_content;
  poppler::document* doc = poppler::document::load_from_file("supermarkt.pdf");

  if (!doc) {
    throw std::runtime_error("Could not open PDF file: supermarkt.pdf");
  }

  for (int i = 0; i < doc->pages(); ++i) {
    poppler::page* p = doc->create_page(i);
    if (p) {
      pdf_content += p->text().to_latin1();
      delete p;
    }
  }
  delete doc;

  assert(pdfData == pdf_content);

  ReadData autoFile{"CMakeLists.txt"};
  std::string autoData = autoFile.ReadAuto();
  std::ifstream automatic_file("CMakeLists.txt");
  std::string automated_content((std::istreambuf_iterator<char>(automatic_file)),
                                std::istreambuf_iterator<char>());
  assert(autoData == automated_content);

  std::cout << "Alle Tests für ReadData waren erfolgreich!" << std::endl;
}
