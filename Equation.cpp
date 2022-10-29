#include "Equation.hpp"
#include <stdexcept>
#include <cmath>
#include <cassert>
#include <iomanip>

void my_assert(bool,const std::string &);

void Equation::set_a(double a) {
    try {
        if (a == 0) {
            throw std::invalid_argument("a cannot be zero.\n");
        }
        else{
            m_a = a;
            update_solutions(m_a,m_b,m_c);
        }
    }
    catch (const std::invalid_argument& e){
        std::cerr << e.what();
    }
}

void Equation::set_b(double b) {
    m_b=b;
    update_solutions(m_a,m_b,m_c);
}

void Equation::set_c(double c) {
    m_c=c;
    update_solutions(m_a,m_b,m_c);
}

void Equation::discriminant() {
    auto res = m_b*m_b - 4*m_a*m_c;
    if (res>0) {
        m_size=2;
        m_ptr=new double[m_size];
        my_assert(m_ptr, "alloc failed");
        m_ptr[0] = (-m_b + sqrt(res)) / (2*m_a);
        m_ptr[1] = (-m_b - sqrt(res)) / (2*m_a);
    }
    else if (res==0){
        m_size=1;
        m_ptr=new double[m_size];
        my_assert(m_ptr, "alloc failed");
        m_ptr[0] = -m_b/(2*m_a);
    }
    else if (res<0){
        m_size=0;
        m_ptr=new double[m_size];
        my_assert(m_ptr, "alloc failed");
    }
}

void Equation::update_solutions(double a,double b,double c) {
   if(m_size >= 0){
       delete[] m_ptr;
   }
   discriminant();
}

void swap(Equation &lhs, Equation &rhs) {
    std::swap(lhs.m_a,rhs.m_a);
    std::swap(lhs.m_b,rhs.m_b);
    std::swap(lhs.m_c,rhs.m_c);
    std::swap(lhs.m_size,rhs.m_size);
    std::swap(lhs.m_ptr,rhs.m_ptr);
}

std::ostream& operator<<(std::ostream &output, const Equation &ref) { //todo: setw()
    output << std::fixed << std::setprecision(1) << ref.m_a << " X^2" << " + ";
    output << std::fixed << std::setprecision(1) << ref.m_b << " X" << " + ";
    output << std::fixed << std::setprecision(1) << ref.m_c << " = " << "0" << std::endl;
    return output;
}

void my_assert(bool cond,const std::string &message){
    if(!cond){
        std::cerr << message << std::endl;
        std::exit(EXIT_FAILURE);
    }
}


