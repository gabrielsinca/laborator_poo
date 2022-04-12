//
// Created by Silviu-Gabriel Sinca on 04.04.2022.
//

#ifndef OOP_MAGAZIN_H
#define OOP_MAGAZIN_H
#include "memory"
#include "vector"
#include "./produse/Produs.h"
/*
 * In clasa asta voi avea date necesare pentru magazin, ex: stoc etc.
 *              + un metoda run() care e practic meniul
 * */

class Magazin {
private:
    static std::vector<std::shared_ptr<Produs>> stoc; // produs si stocul produsului
    static float  bani;

public:
    static void removeFromStoc(const std::shared_ptr<Produs> &produs); // update cand un produs este vandut;
    static void addStoc(const std::shared_ptr<Produs> &produs); // metoda sa adaugi produse in stoc; std::shared_ptr<Produs> prod
    static void showProduse();
    static const std::vector<std::shared_ptr<Produs>> &getStoc();
    static void run();
};
#endif //OOP_MAGAZIN_H
