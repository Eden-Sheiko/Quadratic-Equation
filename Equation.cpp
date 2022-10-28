//
// Created by Eden on 27/10/2022.
//

#include "Equation.h"
#include <stdexcept>
#include <cmath>
#include <cassert>
#include <iomanip>



void Equation::set_a(double a) {
    try {
        if (a==0) {
            throw std::invalid_argument("a cannot be zero.");
        }
        m_a=a;
        update_solutions();
    }
    catch (const std::invalid_argument& e){
        std::cerr << e.what();
    }
}

void Equation::set_b(double b) {
    m_b=b;
    update_solutions();
}

void Equation::set_c(double c) {
    m_c=c;
    update_solutions();
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

void Equation::update_solutions() {

}

void swap(Equation &lhs, Equation &rhs) {
    std::swap(lhs.m_a,rhs.m_a);
    std::swap(lhs.m_b,rhs.m_b);
    std::swap(lhs.m_c,rhs.m_c);
    std::swap(lhs.m_size,rhs.m_size);
    std::swap(lhs.m_ptr,rhs.m_ptr);
}

std::ostream& operator<<(std::ostream &output, const Equation &ref) {
    output << std::fixed << std::setprecision(1) << ref.m_a  << " X^2" << " + ";
    output << std::fixed << std::setprecision(1) << ref.m_b << " X" << " + ";
    output << std::fixed << std::setprecision(1) << ref.m_c << " = " << "0" << std::endl;
    return output;
}
