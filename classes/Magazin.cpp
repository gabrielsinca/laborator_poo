//
// Created by Silviu-Gabriel Sinca on 04.04.2022.
//

#include "Magazin.h"
#include "produse/tipuri/varza/Varza.h"
#include "produse/tipuri/faina/FainaCal1.h"
#include "produse/tipuri/faina/FainaCal2.h"
#include "produse/tipuri/faina/FainaCal3.h"
#include "Exceptii.h"
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
    int index = -1, del = 0;
    for (int i = 0; i < (int) stoc.size(); i++) {
        if (produs->getTipProdus() == stoc[i]->getTipProdus()) {
            if (produs->getMasura() > stoc[i]->getMasura())
                throw TooManyProductsException();
            else if (produs->getMasura() == stoc[i]->getMasura()) {
                index = i;
                del = 1;
            }
            else {
                stoc[i]->setMasura(stoc[i]->getMasura() - produs->getMasura());
            }
            break;
        }
    }

    if (del) {
        std::vector<std::shared_ptr<Produs>> aux;
        for (int i = 0; i < (int) stoc.size(); i++) {
            if (i != index) aux.push_back(stoc[i]);
        }
        stoc.clear();
        stoc = std::move(aux);
        aux.clear();
    }
}

void Magazin::addStoc(const std::shared_ptr<Produs> &produs) {
    stoc.push_back(produs);
}

void Magazin::clientHelp() {
    std::cout << "---------------------------------------------------\n";
    std::cout << "-> Apasa '1' pentru a afisa meniul de client help din nou;\n";
    std::cout << "-> Apasa '2' pentru a afisa stocul magazinului;\n";
    std::cout << "-> Apasa '3' pentru a adauga un produs in cos;\n";
    std::cout << "-> Apasa '4' pentru a afisa cosul de cumparaturi;\n";
    std::cout << "-> Apasa '5' pentru a cumpara produsele selectate;\n";
    std::cout << "---------------------------------------------------\n";
}

void Magazin::proprietarHelp() {
    std::cout << "---------------------------------------------------\n";
    std::cout << "-> Apasa '1' pentru a afisa meniul de proprietar help din nou;\n";
    std::cout << "-> Apasa '2' pentru a afisa stocul magazinului;\n";
    std::cout << "-> Apasa '3' pentru a adauga un produs;\n";
    std::cout << "-> Apasa '4' pentru a afla suma castigata;\n";
    std::cout << "-> Apasa '5' pentru a iesi din meniu;\n";
    std::cout << "---------------------------------------------------\n";
}

void Magazin::clientLoop() {
    int op;
    bool deschis = true;

    std::vector<std::shared_ptr<Produs>> cos; // produs si stocul produsului

    while (deschis) {
        std::cout << "Ce doresti sa faci?\n";
        clientHelp();

        std::cin >> op;

        switch (op) {
            case 1:
                clientHelp();
                break;
            case 2:
                Magazin::showProduse();
                break;
            case 3:
                int prod, masura;
                std::cout << "Ce produs doresti sa cumperi?\n";
                std::cout << "Apasa 1 pentru a cumpara varza;\n";
                std::cout << "Apasa 2 pentru a cumpara faina de calitatea 1;\n";
                std::cout << "Apasa 3 pentru a cumpara faina de calitatea 2;\n";
                std::cout << "Apasa 4 pentru a cumpara faina de calitatea 3;\n";
                std::cin >> prod;

                if (prod == 1) {
                    auto varza = std::make_shared<Varza>();
                    std::cout << "Cate bucati de varza vrei sa cumperi?\n";
                    std::cin >> masura;
                    varza->setMasura(masura);
                    try {
                        cos.push_back(varza);
                        removeFromStoc(varza);
                        bani += varza->calculeazaCost(masura);
                    } catch (const TooManyProductsException &e) {
                        std::cout << e.what() << '\n';
                    }
                } else if (prod == 2) {
                    auto faina = std::make_shared<FainaCal1>();
                    std::cout << "Cate kilograme de faina vrei sa cumperi?\n";
                    std::cin >> masura;
                    faina->setMasura(masura);
                    try {
                        cos.push_back(faina);
                        removeFromStoc(faina);
                        bani += faina->calculeazaCost(masura);
                    } catch (const TooManyProductsException &e) {
                        std::cout << e.what() << '\n';
                    }
                } else if (prod == 3) {
                    auto faina = std::make_shared<FainaCal2>();
                    std::cout << "Cate kilograme de faina vrei sa cumperi?\n";
                    std::cin >> masura;
                    faina->setMasura(masura);
                    try {
                        cos.push_back(faina);
                        removeFromStoc(faina);
                        bani += faina->calculeazaCost(masura);
                    } catch (const TooManyProductsException &e) {
                        std::cout << e.what() << '\n';
                    }
                } else if (prod == 4) {
                    auto faina = std::make_shared<FainaCal3>();
                    std::cout << "Cate kilograme de faina vrei sa cumperi?\n";
                    std::cin >> masura;
                    faina->setMasura(masura);
                    try {
                        cos.push_back(faina);
                        removeFromStoc(faina);
                        bani += faina->calculeazaCost(masura);
                    } catch (const TooManyProductsException &e) {
                        std::cout << e.what() << '\n';
                    }
                } else std::cout<<"Nu ai introdus un numar corect!\n";

                break;
            case 4:
                for (auto produs : cos)
                    produs->print(std::cout);
                break;
            case 5:
                deschis = false;
                break;
            default:
                break;
        }
    }
}

void Magazin::proprietarLoop() {
    int op;
    bool deschis = true;
    while (deschis) {
        std::cout << "Ce doresti sa faci?\n";
        proprietarHelp();

        std::cin >> op;
        switch (op) {
            case 1:
                proprietarHelp();
                break;
            case 2:
                showProduse();
                break;
            case 3:
                int prod, masura;
                std::cout << "Ce produs doresti sa adaugi?\n";
                std::cout << "Apasa 1 pentru a adauga varza;\n";
                std::cout << "Apasa 2 pentru a adauga faina de calitatea 1;\n";
                std::cout << "Apasa 3 pentru a adauga faina de calitatea 2;\n";
                std::cout << "Apasa 4 pentru a adauga faina de calitatea 3;\n";
                std::cin >> prod;

                if (prod == 1) {
                    std::cout << "Cate bucati doresti sa adaugi?\n";
                    auto varza = std::make_shared<Varza>();
                    std::cin >> masura;
                    varza->setMasura(masura);
                    addStoc(varza);
                } else if (prod == 2) {
                    std::cout << "Cate kilograme doresti sa adaugi?\n";
                    auto faina = std::make_shared<FainaCal1>();
                    std::cin >> masura;
                    faina->setMasura(masura);
                    addStoc(faina);
                } else if (prod == 3) {
                    std::cout << "Cate kilograme doresti sa adaugi?\n";
                    auto faina = std::make_shared<FainaCal2>();
                    std::cin >> masura;
                    faina->setMasura(masura);
                    addStoc(faina);
                } else if (prod == 4) {
                    std::cout << "Cate kilograme doresti sa adaugi?\n";
                    auto faina = std::make_shared<FainaCal3>();
                    std::cin >> masura;
                    faina->setMasura(masura);
                    addStoc(faina);
                } else std::cout<<"Nu ai introdus un numar corect!\n";
                break;
            case 4:
                std::cout << bani << " lei\n";
                break;
            case 5:
                deschis = false;
                break;
            default:
                break;
        }
    }
}

void Magazin::run() {
    int optiune;
    bool deschis = true;

    while (deschis) {
        std::cout << "Esti client sau proprietar? Apasa 1 daca esti client si doresti sa cumperi ceva si 2 daca esti proprietarul magazinului si doresti sa actualizezi stocul.\nApasa 0 pentru a iesi din acest meniu.\n";
        std::cin >> optiune;

        switch (optiune) {
            case 0:
                deschis = false;
                break;
            case 1:
                clientLoop();
                break;
            case 2:
                proprietarLoop();
                break;
            default:
                break;
        }
    }

}

