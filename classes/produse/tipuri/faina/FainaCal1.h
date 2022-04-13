//
// Created by Silviu-Gabriel Sinca on 04.04.2022.
//

#ifndef OOP_FAINACAL1_H
#define OOP_FAINACAL1_H
#include "Faina.h"
#include <memory>

class FainaCal1 : public Faina {
private:
    static float pret;

public:
    FainaCal1();
    FainaCal1(float kg);
    FainaCal1(const FainaCal1 &obj);

    ~FainaCal1() override;

    float calculeazaCost(float bucati) const override;
    void print(std::ostream &os) const override;
    static void updatePret(float pret_);

    virtual TipProdus getTipProdus() const override;
    virtual TipFaina getTipFaina() const override;

    bool operator==(const std::shared_ptr<Produs> &faina) const;
    bool operator!=(const std::shared_ptr<Produs> &faina) const;
    FainaCal1& operator=(const FainaCal1 &obj);

    friend std::istream &operator>>(std::istream &is, FainaCal1 &faina);
    friend std::ostream &operator<<(std::ostream &os, const FainaCal1 &faina);
};


#endif //OOP_FAINACAL1_H
