//
// Created by Silviu-Gabriel Sinca on 04.04.2022.
//

#include "FainaCal3.h"

float FainaCal3::pret = 3;

FainaCal3::FainaCal3(const FainaCal3 &obj) : Faina(obj) {}

FainaCal3::FainaCal3(float kg) : Faina(kg) {};

TipProdus FainaCal3::getTipProdus() const {
    return TipProdus::Faina;
}

TipFaina FainaCal3::getTipFaina() const {
    return TipFaina::FainaCal3;
}

FainaCal3::~FainaCal3() {}

float FainaCal3::calculeazaCost(float kg) const {
    return kg * FainaCal3::pret;
}

void FainaCal3::print(std::ostream &os) const {
    os << getMasura() << " kilograme de faina de calitatea 3 vor costa " << calculeazaCost(getMasura()) << " lei.\n";
}

void FainaCal3::updatePret(float pret_) {
    pret += pret_;
}

std::istream &operator>>(std::istream &is, FainaCal3 &faina) {
    std::cout << "Introdu numarul de kilograme de faina de calitatea 3 cumparate: ";
    float kg;
    is >> kg;
    faina.setMasura(kg);
    return is;
}

std::ostream &operator<<(std::ostream &os, const FainaCal3 &faina) {
    faina.print(os);
    return os;
}

bool FainaCal3::operator==(const std::shared_ptr<Produs> &prod) const {
    if (prod->getTipProdus() == FainaCal3::getTipProdus())
        return true;
    return false;
}

bool FainaCal3::operator!=(const std::shared_ptr<Produs> &prod) const {
    return !(prod == *this);
}

FainaCal3 &FainaCal3::operator=(const FainaCal3 &obj) {
    setMasura(obj.getMasura());
    return *this;
}

FainaCal3::FainaCal3() {}
