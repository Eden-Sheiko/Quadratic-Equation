
#ifndef QUADRATIC_EQUATION_TESTS_HPP
#define QUADRATIC_EQUATION_TESTS_HPP

#include "Equation.hpp"

/**
 *  \brief simple test function
 *  the function gets two int and compare them
 *  and additional string for an output massage
 *  @param int
 *  @param int
 *  @param std::string&
 */
void test(int, int, const std::string &);

/**
 *  \brief simple test function
 *  the function gets two objects and compare them
 *  and additional string for an output massage
 *  @param const Equation&
 *  @param const Equation&
 *  @param std::string&
 */
void test_obj(const Equation &, const Equation &, const std::string &);

/**
 *  \brief simple test function
 *  the function gets two const double ptrs and compare them
 *  and additional string for an output massage
 *  @param const double *
 *  @param const double *
 *  @param std::string&
 */
void test_obj_ptrs(const double *, const double *, const std::string &);

void testEquationClass();

void tests();

#endif //QUADRATIC_EQUATION_TESTS_HPP
