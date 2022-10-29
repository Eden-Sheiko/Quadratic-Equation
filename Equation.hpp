//
// Created by Eden on 27/10/2022.
//

#ifndef QUADRATIC_EQUATION_EQUATION_HPP
#define QUADRATIC_EQUATION_EQUATION_HPP
#include <iostream>

class Equation {
    friend void swap(Equation &,Equation &);
    friend std::ostream& operator<<(std::ostream& ,const Equation&);
public:
    //ctor
    Equation(double a,double b,double c)
        :m_b{b},m_c{c}{
        set_a(a);
    }
    //cpy ctor
    Equation(const Equation &other)//todo test a parameter
        :m_a{other.m_a},m_b{other.m_b},m_c{other.m_c},m_size{other.m_size}{
        update_solutions(m_a,m_b,m_c);
        for (auto i = 0; i < other.m_size; ++i) {
            m_ptr[i] = other.m_ptr[i];
        }
    }
    //assignment operator
    Equation & operator=(const Equation &other){
        if(this != &other)
        {
            Equation tmp(other);
            swap(*this,tmp);
        }
        return *this;
    }
    //move ctor
    Equation(Equation &&other)noexcept
            :m_a{other.m_a},m_b{other.m_b},m_c{other.m_c},m_size{other.m_size}{
        m_ptr = (other.m_ptr);

        m_a=0;
        m_b=0;
        m_c=0;
        m_size=0;
        m_ptr= nullptr;
    }
    //move assignment
    Equation &operator=(Equation &&other) noexcept {
        if(this != &other){
            delete[] m_ptr;

            m_a=other.m_a;
            m_b=other.m_b;
            m_c=other.m_c;
            m_size=other.m_size;
            m_ptr=other.m_ptr;

            m_a=0;
            m_b=0;
            m_c=0;
            m_size=0;
            m_ptr= nullptr;
        }
        return *this;
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
    [[nodiscard]] double const *get_solutions()const{return m_ptr;}

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
    void update_solutions(double,double,double);
};


#endif //QUADRATIC_EQUATION_EQUATION_HPP
