#include "Equation.hpp"
#include <stdexcept>
#include <cmath>
#include <iomanip>

constexpr auto param = 4;
constexpr auto denominator_param = 2;

void my_assert(bool, const std::string &);

void Equation::set_a(double a) {
    try {
        if (a == 0) {
            throw std::invalid_argument("a argument cannot be zero.\n");
        } else {
            m_a = a;
            update_solutions_for_discriminant();
        }
    }
    catch (const std::invalid_argument &error) {
        std::cerr << "Invalid argument: " << error.what() << '\n';
    }
}

void Equation::set_b(double b) {
    m_b = b;
    update_solutions_for_discriminant();
}

void Equation::set_c(double c) {
    m_c = c;
    update_solutions_for_discriminant();
}

/**
 * \brief discriminant_calculator function
 *
 * the function handles the 3 solutions
 * if res of the discriminant_calculator bigger then zero
 * then there is 2 roots
 * if res of the discriminant_calculator equals to zero
 * then there is 1 root
 * if res of the discriminant_calculator less then zero
 * there are zero roots
 */
void Equation::discriminant_calculator() {
    auto res = m_b * m_b - param * m_a * m_c;
    if (res > 0) {
        m_size = 2;
        m_ptr = new double[m_size];
        my_assert(m_ptr, "alloc failed");
        m_ptr[0] = (-m_b + sqrt(res)) / (denominator_param * m_a);
        m_ptr[1] = (-m_b - sqrt(res)) / (denominator_param * m_a);
    } else if (res == 0) {
        m_size = 1;
        m_ptr = new double[m_size];
        my_assert(m_ptr, "alloc failed");
        m_ptr[0] = -m_b / (denominator_param * m_a);
    } else if (res < 0) {
        m_size = 0;
        m_ptr = new double[m_size];
        my_assert(m_ptr, "alloc failed");
    }
}

/**
 * \brief update_solutions_for_discriminant of the Equation
 *
 * deletes the dynamic array and calls to the
 * discriminant_calculator() function
 *
 *
 * @see discriminant_calculator()
 */
void Equation::update_solutions_for_discriminant() {
    if (m_size >= 0) {
        delete[] m_ptr;
    }
    discriminant_calculator();
}

void swap(Equation &lhs, Equation &rhs) {
    std::swap(lhs.m_a, rhs.m_a);
    std::swap(lhs.m_b, rhs.m_b);
    std::swap(lhs.m_c, rhs.m_c);
    std::swap(lhs.m_size, rhs.m_size);
    std::swap(lhs.m_ptr, rhs.m_ptr);
}

std::ostream &operator<<(std::ostream &output, const Equation &ref) {
    output << std::fixed << std::setprecision(1) << ref.m_a << std::setw(4) << "X^2"
           << std::setw(2) << "+" << std::setw(5);
    output << std::fixed << std::setprecision(1) << ref.m_b << std::setw(2) << "X"
           << std::setw(2) << "+" << std::setw(5);
    output << std::fixed << std::setprecision(1) << ref.m_c << std::setw(2) << "="
           << std::setw(2) << "0";
    return output;
}

/**
 *
 * \brief my_assert
 *  is assert function.
 * @param bool cond
 * @param const std::string & message
 */
void my_assert(bool cond, const std::string &message) {
    if (!cond) {
        std::cerr << message << std::endl;
        std::exit(EXIT_FAILURE);
    }
}