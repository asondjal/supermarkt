#include "base/warenkorb.hpp"

#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

static int warenkorb_counter = 0;

Warenkorb::Warenkorb(std::shared_ptr<Kunde> kunde)
    : kunde_(std::move(kunde)), warenkorbID_(warenkorb_counter++) {}

void Warenkorb::AddProdukt(Produkt* produkt) { produkte.push_back(produkt); }

void Warenkorb::RemoveProdukt(Produkt* produkt) {
  auto it = std::find(produkte.begin(), produkte.end(), produkt);
  if (it != produkte.end()) {
    produkte.erase(it);
  }
}

float Warenkorb::GetGesamtPreis() const {
  std::cout << std::fixed << std::setprecision(2);
  float gesamtPreis = 0.0;
  for (const auto& produkt : produkte) {
    gesamtPreis += produkt->GetGesamtPreis();
  }
  return gesamtPreis;
}

std::vector<Produkt*> Warenkorb::GetProdukte() const { return produkte; }

std::shared_ptr<Kunde> Warenkorb::GetKunde() const { return kunde_; }

int Warenkorb::GetWarenkorbID() const { return warenkorbID_; }

bool Warenkorb::operator==(const Warenkorb& other) const {
  return warenkorbID_ == other.GetWarenkorbID();
}
