//
// Created by Silviu-Gabriel Sinca on 12.04.2022.
//

#include "Exceptii.h"

const char *TooManyProductsException::what() const noexcept {
    return "Nu avem destule produse de acest tip in stoc!";
}
