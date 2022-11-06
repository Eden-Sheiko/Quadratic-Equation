#ifndef QUADRATIC_EQUATION_EQUATION_HPP
#define QUADRATIC_EQUATION_EQUATION_HPP

#include <iostream>

/**
 * \brief class Equation which managers quadratic Equation.
 *
 */
class Equation {
    /**
     * \brief swaps two Equation objects.
     *
     *  friend function that has access to the private
     *  data members.
     *
     *  \param Equation& first obj to swap
     *  \param Equation& second obj to swap
    */
    friend void swap(Equation &, Equation &);

    /**
     * \brief operator << overloading
     *
     * friend function that has access to the private
     *  data members.
     *  the following function can print Equation objects
     * \param std::ostream& first ostream object
     * \param const Equation& second object
     *
     * \return std::ostream object
     */
    friend std::ostream &operator<<(std::ostream &, const Equation &);

public:
    /**
     * \brief user defined parametric ctor
     *
     *  the ctor has function that checks if a is zero,
     *  @see set_a()
     *
     * @param a (double)the first argument.
     * @param b (double)the second argument.
     * @param c (double)the third argument.
     */
    Equation(double a, double b, double c)
            : m_b{b}, m_c{c} {
        set_a(a);
    }

    /**
     * \brief user defined parametric cpy ctor
     * @param other Equation &
     * the ctor has function that checks if a is zero,
     * @see set_a()
     */
    Equation(const Equation &other)
            : m_b{other.m_b}, m_c{other.m_c}, m_size{other.m_size} {
        set_a(other.m_a);
        for (auto i = 0; i < other.m_size; ++i) {
            m_ptr[i] = other.m_ptr[i];
        }
    }

    /**
     * @brief assignment operator
     *
     * the function uses copy and swap idiom
     * and calls to the cpy ctor
     * @see swap()
     * the function also checks for self assessment
     * the function handles a = 0 case
     * @see set_a()
     * @param other const Equation &
     * @return *this
     */
    Equation &operator=(const Equation &other) {
        if (this != &other) {
            Equation tmp(other);
            swap(*this, tmp);
        }
        return *this;
    }

    /**
     * \brief move ctor
     *
     * the function handles a = 0 case
     * @see set_a()
     *
     * @param other Equation &&
     */
    Equation(Equation &&other) noexcept
            : m_b{other.m_b}, m_c{other.m_c}, m_size{other.m_size} {
        set_a(other.m_a);
        m_ptr = (other.m_ptr);
        other.m_a = 0;
        other.m_b = 0;
        other.m_c = 0;
        other.m_size = 0;
        other.m_ptr = nullptr;
    }

    /**
     * \brief move assignment
     *
     * the function handles a = 0 case
     * @see set_(a)
     * @param other Equation &&
     * @return *this
     */
    Equation &operator=(Equation &&other) noexcept {
        if (this != &other) {
            set_a(other.m_a);
            m_b = other.m_b;
            m_c = other.m_c;
            m_size = other.m_size;
            m_ptr = other.m_ptr;

            other.m_a = 0;
            other.m_b = 0;
            other.m_c = 0;
            other.m_size = 0;
            other.m_ptr = nullptr;
        }
        return *this;
    }

    /**
     * \brief dtor
     */
    ~Equation() {
        delete[] m_ptr;
        m_ptr = nullptr;
        m_size = 0;
        m_a = 0;
        m_b = 0;
        m_c = 0;
    }

    /// getters
    [[nodiscard]] double get_a() const { return m_a; }

    [[nodiscard]] double get_b() const { return m_b; }

    [[nodiscard]] double get_c() const { return m_c; }

    [[nodiscard]] std::size_t get_solutions_size() const { return m_size; }

    /**
     * i assume that the user will not use get_solutions() when the index is
     * invalid or wrong
     * @return double
     */
    [[nodiscard]] double const *get_solutions() const { return m_ptr; }

    /// setters
    /// each setter call @see  update_solutions_for_discriminant()
    /// to update after change was made to the
    /// params
    /// @see set_a() handles a = 0 case
    void set_a(double);

    void set_b(double);

    void set_c(double);

private:
    double m_a{};
    double m_b{};
    double m_c{};
    double *m_ptr{};
    std::size_t m_size{};

    /**
     *  \brief void functions that calculates find_roots
     */
    void find_roots();
};

/**
 * \brief operator+ overloading.
 *
 * receives 2 const Equation &
 *
 * @param lhs const Equation &
 * @param rhs const Equation &
 * @return Equation obj
 */
inline Equation operator+(const Equation &lhs, const Equation &rhs) {
    Equation tmp(lhs.get_a(), lhs.get_b(), lhs.get_c());
    tmp.set_a(lhs.get_a() + rhs.get_a());
    tmp.set_b(lhs.get_b() + rhs.get_b());
    tmp.set_c(lhs.get_c() + rhs.get_c());
    return tmp;
}

/**
 * \brief operator+ overloading.
 *
 * receives first arg as double and sec arg as Equation
 *
 * @param lhs const Equation &
 * @param rhs const double
 * @return Equation obj
 */
inline Equation operator+(const double lhs, const Equation &rhs) {
    Equation tmp(rhs.get_a(), rhs.get_b(), rhs.get_c());
    tmp.set_c(lhs + rhs.get_c());
    return tmp;
}

/**
 * \brief operator+ overloading.
 *
 * receives first arg as Equation and sec arg as double
 *
 * @param lhs const double
 * @param rhs const Equation &
 * @return Equation obj
 */
inline Equation operator+(const Equation &lhs, const double rhs) {
    Equation tmp(lhs.get_a(), lhs.get_b(), lhs.get_c());
    tmp.set_c(lhs.get_c() + rhs);
    return tmp;
}

/**
 * \brief operator+ overloading.
 *
 * receives first arg as Equation and sec arg as Equation
 * and compares between the two objects
 *
 * @param lhs const Equation &
 * @param rhs const Equation &
 * @return bool
 */
inline bool operator==(const Equation &lhs, const Equation &rhs) {
    return (lhs.get_a() == rhs.get_a() && lhs.get_b() == rhs.get_b() &&
            lhs.get_c() == rhs.get_c() && *lhs.get_solutions() == *rhs.get_solutions() &&
            lhs.get_solutions_size() == rhs.get_solutions_size());
}

#endif //QUADRATIC_EQUATION_EQUATION_HPP