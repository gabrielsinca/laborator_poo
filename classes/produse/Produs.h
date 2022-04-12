//
// Created by Silviu-Gabriel Sinca on 04.04.2022.
//

#ifndef OOP_Produs_H
#define OOP_Produs_H
#include <iostream>

enum class TipProdus {
    Varza,
    Faina
};

class Produs {
private:
    // poate fi la bucata/volum/kg;
    float cost = 0;
    float masura;

protected:
public:
    Produs(); // optional
    Produs(float masura); // voi folosi acest tip de constructor in general, voi face pretul produselor static si privat, iar cand un client vrea sa cumpere produsul, va specifica doar numarul de produse/kg/volum pe care vrea
    Produs(const Produs &obj);

    virtual ~Produs();

    float getMasura() const;
    void setMasura(float masura_);

    float getCost() const;
    void setCost(float cost_);

    virtual float calculeazaCost(float masura_) const = 0;

    virtual void print(std::ostream &os) const = 0;
    virtual TipProdus getTipProdus() const = 0;

    Produs& operator=(const Produs &obj);

//    friend std::istream &operator>>(std::istream &is, Produs &produs);
//    friend std::ostream &operator<<(std::ostream &os, const Produs &Produs);
};

#endif //OOP_Produs_H
