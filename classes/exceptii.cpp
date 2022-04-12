//
// Created by Silviu-Gabriel Sinca on 12.04.2022.
//

#include "exceptii.h"

const char *TooManyProductsException::what() const noexcept {
    return "Nu avem destule produse de acest tip in stoc!";
}
