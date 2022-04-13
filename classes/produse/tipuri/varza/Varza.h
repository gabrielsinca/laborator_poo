//
// Created by Silviu-Gabriel Sinca on 04.04.2022.
//

#ifndef OOP_VARZA_H
#define OOP_VARZA_H
#include "./../../Produs.h"
#include <memory>

class Varza : public Produs {
private:
    static float pret;

public:
    Varza();
    Varza(float bucati);
    Varza(const Varza &obj);
    ~Varza() override;

    virtual float calculeazaCost(float bucati) const override;
    virtual void print(std::ostream &os) const override;
    static void updatePret(float pret_);

    virtual TipProdus getTipProdus() const override {
        return TipProdus::Varza;
    }

    bool operator==(const std::shared_ptr<Produs> &varza) const;
    bool operator!=(const std::shared_ptr<Produs> &varza) const;

    Varza& operator=(const Varza &obj);

    friend std::istream &operator>>(std::istream &is, Varza &varza);
    friend std::ostream &operator<<(std::ostream &os, const Varza &varza);
};


#endif //OOP_VARZA_H
