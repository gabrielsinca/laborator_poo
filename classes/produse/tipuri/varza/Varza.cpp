//
// Created by Silviu-Gabriel Sinca on 04.04.2022.
//

#include "Varza.h"

float Varza::pret = 2; // static stuff

Varza::Varza(float masura) : Produs(masura) {}

float Varza::calculeazaCost(float bucati) const {
    return bucati*Varza::pret;
}

void Varza::updatePret(float pret_) {
    pret += pret_;
}

std::istream &operator>>(std::istream &is, Varza &varza) {
    std::cout << "Introdu numarul de bucati cumparate: ";
    float bucati;
    is >> bucati;
    varza.setMasura(bucati);
    return is;
}

void Varza::print(std::ostream &os) const {
    os << getMasura() << " bucati de varza vor costa " << calculeazaCost(getMasura()) << " lei.\n";
}

std::ostream &operator<<(std::ostream &os, const Varza &varza) {
    varza.print(os);
    return os;
}

bool Varza::operator==(const std::shared_ptr<Produs> &prod) const {
    if (prod->getTipProdus() == Varza::getTipProdus())
        return true;
    return false;
}

bool Varza::operator!=(const std::shared_ptr<Produs> &prod) const {
    return !(prod == *this);
}

Varza::Varza(const Varza &obj) : Produs(obj){}

Varza &Varza::operator=(const Varza &obj) {
    this->setMasura(obj.getMasura());
    return *this;
}

Varza::~Varza() {}

Varza::Varza() { }
