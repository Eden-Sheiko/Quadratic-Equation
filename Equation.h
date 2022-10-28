//
// Created by Eden on 27/10/2022.
//

#ifndef QUADRATIC_EQUATION_EQUATION_H
#define QUADRATIC_EQUATION_EQUATION_H
#include <iostream>

class Equation {
    friend void swap(Equation &,Equation &);
    friend std::ostream& operator<<(std::ostream& ,const Equation&);
public:
    //todo: rule of 5
    //ctor
    Equation():m_a{},m_b{},m_c{},m_size{},m_ptr{}
    {}
    Equation(double a,double b,double c)
        :m_b{b},m_c{c}{
        set_a(a);
    }
    //cpy ctor
    Equation(const Equation &other)
        :m_a{other.m_a},m_b{other.m_b},m_c{other.m_c},m_size{other.m_size}{
        update_solutions(m_a,m_b,m_c); //todo: test for needed loop
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
    Equation &operator=(Equation &&other){
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
        m_size=0;
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
    //operator

private:
    double m_a {};
    double m_b {};
    double m_c {};
    double *m_ptr {};
    std::size_t m_size {};
    void update_solutions(double,double,double);
};

inline Equation operator+(const Equation &lhs,const Equation &rhs){
    Equation tmp;
    tmp.set_a(lhs.get_a()+rhs.get_a());
    tmp.set_b(lhs.get_b()+rhs.get_b());
    tmp.set_c(lhs.get_c()+rhs.get_c());
    tmp.discriminant();
    return tmp;
}
inline Equation operator+(const Equation &lhs,double number){
    Equation tmp;
    tmp.set_c(lhs.get_c()+number);
    tmp.discriminant();
    return tmp;
}
inline Equation operator+(double number,const Equation &rhs){
    Equation tmp;
    tmp.set_c(rhs.get_c()+number);
    tmp.set_b(rhs.get_b());
    tmp.set_c(rhs.get_c());
    return tmp;
}




#endif //QUADRATIC_EQUATION_EQUATION_H
