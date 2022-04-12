//
// Created by Silviu-Gabriel Sinca on 04.04.2022.
//

#ifndef OOP_FAINA_H
#define OOP_FAINA_H
#include "../../Produs.h"

enum class TipFaina {
    FainaCal1,
    FainaCal2,
    FainaCal3
};

class Faina : public Produs{
private:
    static float pret;

public:
    Faina();
    Faina(float kg);
    Faina(const Faina &obj); // cc

    virtual ~Faina();

//    virtual float calculeazaCost(float kg) const override = 0;
    virtual TipFaina getTipFaina() const = 0;
    virtual TipProdus getTipProdus() const override;
};


#endif //OOP_FAINA_H
