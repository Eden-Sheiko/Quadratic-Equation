#include "Equation.h"

int main() {
    Equation eqa(1,-3,-10);
    Equation eq2 = eqa;
    Equation eq3(1,1,1);
    eq3 = eq2;
    std::cout << eqa;
    std::cout << eq2;
    std::cout << eq3;
    eq3.set_c(0);
    //testing
    std::cout << "0000000000000000" << std::endl;
    using namespace std;
    Equation eq(10,20,30);
    cout << eq << endl;
//should print: 10X^2 + 20X + 30 = 0
    cout << eq.get_solutions_size() << endl;
//should print 0
    //eq = -20 + eq;



    return 0;

}
