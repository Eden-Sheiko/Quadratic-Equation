
#include "Tests.hpp"


void test(int expected, int actual,const std::string &testName){
    if(expected==actual){
        std::cout << testName << " PASSED" << std::endl;
    }
    else{
        std::cout << testName << " FAILED!!!" << std::endl;
        std::cout << " expected " << expected << " but was " << actual << std::endl;
    }
}

void test_obj(const Equation &expected,const Equation &actual,const std::string &testName){
    if(expected==actual){
        std::cout << testName << " PASSED" << std::endl;
    }
    else{
        std::cout << testName << " FAILED!!!" << std::endl;
        std::cout << " expected " << expected << " but was " << actual << std::endl;
    }
}
void test_obj_ptrs(const double *expected,const double *actual,const std::string &testName){
    if(expected==actual){
        std::cout << testName << " FAILED!!! shallow copy" << std::endl;
    }
    else{
        std::cout << testName << " PASSED!!!" << std::endl;
        std::cout << "address : " << expected << "address : " << actual << std::endl;
    }
}

void testEquationClass(){
    std::cout << "--------TESTS!!!--------" << std:: endl;
    std::cout << "--------setters & getters tests!!!--------" << std:: endl;
    Equation t1(1,2,3);
    test(1,t1.get_a(),"test get_a");
    test(2,t1.get_b(),"test get_b");
    test(3,t1.get_c(),"test get_c");
    t1.set_a(5);
    t1.set_b(10);
    t1.set_c(15);
    test(5,t1.get_a(),"test set_a");
    test(10,t1.get_b(),"test set_b");
    test(15,t1.get_c(),"test set_c");
    std::cout << "--------operators--------" << std:: endl;
    Equation t2(1,2,3);
    Equation t3(1,2,3);
    Equation t4 = t2+t3;
    Equation t5_test(2,4,6);
    test_obj(t5_test,t4,"operator + (obj+obj) test");
    double test1 = 25;
    Equation t6(10,10,10);
    Equation t6_test(10,10,35);
    t6 = test1 + t6;
    test_obj(t6_test,t6,"operator + (double+obj) test");
    double test2 = 40;
    Equation t7(10,10,10);
    t7 = t7 + test2;
    Equation t7_test(10,10,50);
    test_obj(t7_test,t7,"operator + (obj+double) test");
    Equation t8(10,20,30);
    Equation t8_test(10,20,30);
    test_obj(t8_test,t8,"comparison operator test (obj==obj)");
    Equation t9_test(3,24,48);
    Equation t10_test(1,3,-4);
    std::cout << "--------Logic--------" << std:: endl;
    test(0,t8_test.get_solutions_size(),"testing (Discriminant < 0)");
    test(1,t9_test.get_solutions_size(),"testing (Discriminant = 0)");
    test(2,t10_test.get_solutions_size(),"testing (Discriminant > 0)");
    std::cout << "--------copy ctor and copy assignment --------" << std:: endl;
    Equation t11(1,2,3);
    Equation t12(t11);
    std::cout <<"copy ctor test" << std::endl;
    test(t11.get_a(),t12.get_a(),"values -> get(a) test");
    test(t11.get_b(),t12.get_b(),"values -> get(b) test");
    test(t11.get_c(),t12.get_c(),"values -> get(c) test");
    test(t11.get_solutions_size(),t12.get_solutions_size(),"values -> size of solutions test");
    test(*t11.get_solutions(),*t12.get_solutions(),"values -> dereference solutions test");
    test_obj_ptrs(&(*t11.get_solutions()),&(*t12.get_solutions()),"values -> dereference solutions test");
    std::cout << "----------------" << std:: endl;
    std::cout <<"copy assignment test" << std::endl;
    Equation t13(4,5,6);
    Equation t14(7,8,9);
    t14=t13;
    test(t14.get_a(),t13.get_a(),"values -> get(a) test");
    test(t14.get_b(),t13.get_b(),"values -> get(b) test");
    test(t14.get_c(),t13.get_c(),"values -> get(c) test");
    test(t14.get_solutions_size(),t13.get_solutions_size(),"values -> size of solutions test");
    test(*t14.get_solutions(),*t13.get_solutions(),"values -> dereference solutions test");
    test_obj_ptrs(&(*t14.get_solutions()),&(*t13.get_solutions()),"values -> dereference solutions test");
}

void tests(){
    using namespace std;
    Equation eq(10,20,30);
    cout << eq << endl;
//should print: 10X^2 + 20X + 30 = 0
    cout << eq.get_solutions_size() << endl;
//should print 0
    eq = -20 + eq;
    cout << eq << endl;
//should print: 10X^2 + 20X + 10 = 0
    cout << eq.get_solutions_size() << endl;
//should print 1
    cout << eq.get_solutions()[0] << endl;
//should print -1
    cout << Equation(1,5,3) + Equation(2,6,4) << endl;
//should print: 3X^2 + 11X + 7 = 0
    eq = Equation(1,3,-4);
    cout << eq << endl;
//should print 1X^2 + 3X + -4 = 0
    cout << eq.get_solutions_size() << endl;
//should print 2
    cout << "X1 = " << eq.get_solutions()[0] << endl;
//should print: X1 = 1
    cout << "X2 = " << eq.get_solutions()[1] << endl;
//should print: X2 = -4
}
