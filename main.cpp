#include <iostream>
#include "./classes/produse/Produs.h"
#include "./classes/produse/tipuri/varza/Varza.h"
#include "./classes/Magazin.h"
#include "./classes/produse/tipuri/faina/FainaCal1.h"
#include "memory"

/*
 * Problema: Magazin
 * Link: https://octav.cc/ub/poo/teme135_2014.pdf
 * */

int main() {

    auto varza2 = std::make_shared<Varza>(0);
    auto faina = std::make_shared<FainaCal1>(3);
    auto faina1 = std::make_shared<FainaCal1>(5);

    faina1 = faina;

    std::cout << faina->getMasura() << ' ' << faina1->getMasura();


    return 0;
}
