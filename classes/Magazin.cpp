//
// Created by Silviu-Gabriel Sinca on 04.04.2022.
//

#include "Magazin.h"

#include <utility>

std::vector<std::shared_ptr<Produs>> Magazin::stoc;
float Magazin::bani = 0;

const std::vector<std::shared_ptr<Produs>> &Magazin::getStoc() {
    return stoc;
}

void Magazin::showProduse() {
    for (const auto& prod : stoc) {
        prod->print(std::cout);
    }
}

void Magazin::removeFromStoc(const std::shared_ptr<Produs> &produs) {

    for (int i = 0; i < (int) stoc.size(); i++) {
        if (produs == stoc[i]) {
            produs->print(std::cout);
            if (produs->getMasura() < stoc[i]->getMasura()) {
                stoc[i]->setMasura(stoc[i]->getMasura() - produs->getMasura());
            } else if (produs->getMasura() == stoc[i]->getMasura()) {
                for (int j = i + 1; j < (int) stoc.size(); j++) {
                    stoc[j-1] = stoc[j];
                }
            } else std::cout << "Nu sunt destule produse de acest tip pentru a elimina " << produs->getMasura() << " bucati!\n";
            break;
        }
    }
    for (auto prod : stoc)
        std::cout << prod->getMasura() << '\n';
}

void Magazin::addStoc(const std::shared_ptr<Produs> &produs) {
    stoc.push_back(produs);
}


void Magazin::run() {
    std::cout << "WREEEEEEEEEEEEEEEEEE\n";
}




