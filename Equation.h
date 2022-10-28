//
// Created by Eden on 27/10/2022.
//

#ifndef QUADRATIC_EQUATION_EQUATION_H
#define QUADRATIC_EQUATION_EQUATION_H
#include <iostream>

class Equation {
public:
    //ctor
    Equation(double a,double b,double c)
        :m_b{b},m_c{c}{
        set_a(a);
        discriminant();
        update_solutions();
    }

    Equation(const Equation &other){
        m_a=other.m_a;
        m_b=other.m_b;
        m_c=other.m_c;
        m_size=other.m_size;
        discriminant();
        for (auto i = 0; i < other.m_size; ++i) {
            m_ptr[i] = other.m_ptr[i];
        }
    }

    ~Equation(){
        delete[] m_ptr; //todo: maybe to check if there was no alloc
        m_ptr = nullptr;
        m_a=0;
        m_b=0;
        m_c=0;
    }


    //setters & getters
    [[nodiscard]] double get_a()const{return m_a;}
    [[nodiscard]] double get_b()const{return m_b;}
    [[nodiscard]] double get_c()const{return m_c;}
    [[nodiscard]] std::size_t get_solutions_size()const{return m_size;}
    [[nodiscard]] double const *const get_solutions()const{return m_ptr;}

    void set_a(double);
    void set_b(double);
    void set_c(double);

    //functions
    void discriminant();

private:
    double m_a {};
    double m_b {};
    double m_c {};
    double *m_ptr {};
    std::size_t m_size {};
    void update_solutions();
};


#endif //QUADRATIC_EQUATION_EQUATION_H
