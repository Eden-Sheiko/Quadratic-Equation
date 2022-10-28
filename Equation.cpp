//
// Created by Eden on 27/10/2022.
//

#include "Equation.h"
#include <stdexcept>

void Equation::set_a(double a) {
    try {
        if (a==0) {
            throw std::invalid_argument("a cannot be zero.");
        }
        m_a=a;
    }
    catch (const std::invalid_argument& e){
        std::cerr << e.what();
    }
}

void Equation::set_b(double b) {
    m_b=b;
}

void Equation::set_c(double c) {
    m_c=c;
}
