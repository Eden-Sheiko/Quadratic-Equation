#include "Equation.h"

int main() {
    Equation eqa(1,-3,-10);
    Equation eq2(eqa);
    Equation eq3(1,1,1);
    eq3 = eq2;
    std::cout << eqa;
    std::cout << eq2;
    std::cout << eq3;
    eq3.set_c(0);
    //testing
    std::cout << "0000000000000000" << std::endl;








    return 0;

}
