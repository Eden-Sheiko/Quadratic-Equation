#include "Equation.h"

int main() {
    Equation eq(1,-3,-10);
    Equation eq2 = eq;
    Equation eq3(1,1,1);
    eq3 = eq2;
    std::cout << eq;
    std::cout << eq2;
    std::cout << eq3;
    eq3.set_c(0);



    return 0;

}
