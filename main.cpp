#include "Equation.hpp"

void test(int,int,const std::string&);

void testEquationClass();

void tests();

int main() {

    tests();
    testEquationClass();

//Equation q1(-1,-3.4,-4.2);
//std::cout << q1.get_solutions()[0];
    return 0;
}

void test(int expected, int actual,const std::string &testName){
    if(expected==actual){
        std::cout << testName << " PASSED" << std::endl;
    }
    else{
        std::cout << testName << " FAILED!!!" << std::endl;
        std::cout << " expected " << expected << " but was " << actual << std::endl;
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
    Equation t3 = t1+t2;
    test(t3.get_a() == 2 && t3.get_b() == 4 && t3.get_c() == 6 ,t3.get_a() == 2 && t3.get_b() == 4 && t3.get_c() == 6,
         "operator obj+obj test");



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
