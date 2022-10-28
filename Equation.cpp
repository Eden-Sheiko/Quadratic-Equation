//
// Created by Eden on 27/10/2022.
//

#include "Equation.h"
#include <stdexcept>
#include <cmath>
#include <cassert>

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

void Equation::discriminant() {
    auto res = m_b*m_b - 4*m_a*m_c;
    if (res>0) {
        m_size=2;
        m_ptr=new double[m_size];
        assert(m_ptr);
        m_ptr[0] = (-m_b + sqrt(res)) / (2*m_a);
        m_ptr[1] = (-m_b - sqrt(res)) / (2*m_a);

    }
    else if (res==0){
        m_size=1;
        m_ptr=new double[m_size];
        assert(m_ptr);
        m_ptr[0] = -m_b/(2*m_a);
    }
    else if (res<0){
        m_size=0;
        m_ptr=new double[m_size];
        assert(m_ptr);
    }
}
