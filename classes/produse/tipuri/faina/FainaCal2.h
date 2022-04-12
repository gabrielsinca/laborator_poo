//
// Created by Silviu-Gabriel Sinca on 04.04.2022.
//

#ifndef OOP_FAINACAL2_H
#define OOP_FAINACAL2_H
#include "Faina.h"

class FainaCal2 : public Faina {
private:
    static float pret;

public:
    FainaCal2();
    FainaCal2(float kg);
    FainaCal2(const FainaCal2 &obj);

    ~FainaCal2() override;

    float calculeazaCost(float bucati) const override;
    void print(std::ostream &os) const override;
    static void updatePret(float pret_);

    virtual TipProdus getTipProdus() const override;
    virtual TipFaina getTipFaina() const override;

    bool operator==(const std::shared_ptr<Produs> &faina) const;
    bool operator!=(const std::shared_ptr<Produs> &faina) const;
    FainaCal2& operator=(const FainaCal2 &obj);

    friend std::istream &operator>>(std::istream &is, FainaCal2 &faina);
    friend std::ostream &operator<<(std::ostream &os, const FainaCal2 &faina);
};


#endif //OOP_FAINACAL2_H
