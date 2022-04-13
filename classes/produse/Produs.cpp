//
// Created by Silviu-Gabriel Sinca on 04.04.2022.
//

#include "Produs.h"

Produs::Produs() { }

Produs::Produs(float masura) : masura(masura) {}

float Produs::getMasura() const {
    return masura;
}

void Produs::setMasura(float masura_) {
    masura = masura_;
}

float Produs::getCost() const {
    return cost;
}

void Produs::setCost(float cost_) {
    cost = cost_;
}

Produs::~Produs() { }

Produs::Produs(const Produs &obj) {
    this->setMasura(obj.getMasura());
}

Produs &Produs::operator=(const Produs &obj) {
    masura = obj.getMasura();
    return *this;
}
