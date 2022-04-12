//
// Created by Silviu-Gabriel Sinca on 04.04.2022.
//

#include "FainaCal1.h"

float FainaCal1::pret = 5;

FainaCal1::FainaCal1(const FainaCal1 &obj) {
    this->setMasura(obj.getMasura());
}

FainaCal1::FainaCal1(float kg) : Faina(kg) {};

TipProdus FainaCal1::getTipProdus() const {
    return TipProdus::Faina;
}

TipFaina FainaCal1::getTipFaina() const {
    return TipFaina::FainaCal1;
}

FainaCal1::~FainaCal1() {}

float FainaCal1::calculeazaCost(float kg) const {
    return kg * FainaCal1::pret;
}

void FainaCal1::print(std::ostream &os) const {
    os << getMasura() << " kilograme de faina de calitatea 1 vor costa " << calculeazaCost(getMasura()) << " lei.\n";
}

void FainaCal1::updatePret(float pret_) {
    pret += pret_;
}

std::istream &operator>>(std::istream &is, FainaCal1 &faina) {
    std::cout << "Introdu numarul de kilograme de faina de calitatea 1 cumparate: ";
    float kg;
    is >> kg;
    faina.setMasura(kg);
    return is;
}

std::ostream &operator<<(std::ostream &os, const FainaCal1 &faina) {
    faina.print(os);
    return os;
}

bool FainaCal1::operator==(const std::shared_ptr<Produs> &prod) const {
    if (prod->getTipProdus() == FainaCal1::getTipProdus())
        return true;
    return false;
}

bool FainaCal1::operator!=(const std::shared_ptr<Produs> &prod) const {
    return !(prod == *this);
}

FainaCal1 &FainaCal1::operator=(const FainaCal1 &obj) {
    setMasura(obj.getMasura());
    return *this;
}
