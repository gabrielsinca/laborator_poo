//
// Created by Silviu-Gabriel Sinca on 04.04.2022.
//

#ifndef OOP_FAINACAL3_H
#define OOP_FAINACAL3_H
#include "Faina.h"

class FainaCal3 : public Faina{
private:
    static float pret;

public:
    FainaCal3();
    FainaCal3(float kg);
    FainaCal3(const FainaCal3 &obj);

    ~FainaCal3() override;

    float calculeazaCost(float bucati) const override;
    void print(std::ostream &os) const override;
    static void updatePret(float pret_);

    virtual TipProdus getTipProdus() const override;
    virtual TipFaina getTipFaina() const override;

    bool operator==(const std::shared_ptr<Produs> &faina) const;
    bool operator!=(const std::shared_ptr<Produs> &faina) const;
    FainaCal3& operator=(const FainaCal3 &obj);

    friend std::istream &operator>>(std::istream &is, FainaCal3 &faina);
    friend std::ostream &operator<<(std::ostream &os, const FainaCal3 &faina);
};


#endif //OOP_FAINACAL3_H
