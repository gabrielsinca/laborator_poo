//
// Created by Silviu-Gabriel Sinca on 04.04.2022.
//

#include "FainaCal2.h"

float FainaCal2::pret = 4;

FainaCal2::FainaCal2(const FainaCal2 &obj) {
    this->setMasura(obj.getMasura());
}

FainaCal2::FainaCal2(float kg) : Faina(kg) {};

TipProdus FainaCal2::getTipProdus() const {
    return TipProdus::Faina;
}

TipFaina FainaCal2::getTipFaina() const {
    return TipFaina::FainaCal2;
}

FainaCal2::~FainaCal2() {}

float FainaCal2::calculeazaCost(float kg) const {
    return kg * FainaCal2::pret;
}

void FainaCal2::print(std::ostream &os) const {
    os << getMasura() << " kilograme de faina de calitatea 2 vor costa " << calculeazaCost(getMasura()) << " lei.\n";
}

void FainaCal2::updatePret(float pret_) {
    pret += pret_;
}

std::istream &operator>>(std::istream &is, FainaCal2 &faina) {
    std::cout << "Introdu numarul de kilograme de faina de calitatea 2 cumparate: ";
    float kg;
    is >> kg;
    faina.setMasura(kg);
    return is;
}

std::ostream &operator<<(std::ostream &os, const FainaCal2 &faina) {
    faina.print(os);
    return os;
}

bool FainaCal2::operator==(const std::shared_ptr<Produs> &prod) const {
    if (prod->getTipProdus() == FainaCal2::getTipProdus())
        return true;
    return false;
}

bool FainaCal2::operator!=(const std::shared_ptr<Produs> &prod) const {
    return !(prod == *this);
}

FainaCal2 &FainaCal2::operator=(const FainaCal2 &obj) {
    setMasura(obj.getMasura());
    return *this;
}
