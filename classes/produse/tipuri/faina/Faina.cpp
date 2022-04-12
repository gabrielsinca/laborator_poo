//
// Created by Silviu-Gabriel Sinca on 04.04.2022.
//

#include "Faina.h"

Faina::Faina() {}

Faina::Faina(float kg) : Produs(kg){};

Faina::Faina(const Faina &obj) {
    this->setMasura(obj.getMasura());
}

Faina::~Faina() {}

TipProdus Faina::getTipProdus() const {
    return TipProdus::Faina;
}

