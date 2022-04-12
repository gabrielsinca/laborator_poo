#include <iostream>
#include "memory"
#include "./classes/Magazin.h"
#include "./classes/produse/Produs.h"
#include "./classes/produse/tipuri/varza/Varza.h"
#include "./classes/produse/tipuri/faina/FainaCal1.h"
#include "classes/produse/tipuri/faina/FainaCal2.h"
#include "classes/produse/tipuri/faina/FainaCal3.h"

/*
 * Problema: Magazin
 * Link: https://octav.cc/ub/poo/teme135_2014.pdf
 * */

int main() {
/*
    auto varza = std::make_shared<Varza>(2);
    auto faina1 = std::make_shared<FainaCal1>(3);
    auto faina2 = std::make_shared<FainaCal2>(5);
    auto faina3 = std::make_shared<FainaCal3>(1);

    Magazin::addStoc(varza);
    Magazin::addStoc(faina1);
    Magazin::addStoc(faina2);
    Magazin::addStoc(faina3);

    Magazin::showProduse();
    Magazin::removeFromStoc(std::make_shared<Varza>(1));
    std::cout<<"=============\n";
    Magazin::showProduse();
*/
    Magazin::run();

    return 0;
}
