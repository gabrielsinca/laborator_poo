//
// Created by Silviu-Gabriel Sinca on 12.04.2022.
//

#ifndef OOP_EXCEPTII_H
#define OOP_EXCEPTII_H


#include <exception>

class TooManyProductsException : public std::exception {
public:
    TooManyProductsException() = default;
    const char * what() const noexcept override;
};


#endif //OOP_EXCEPTII_H
