#include "Equation.h"

int main() {
    Equation eq(1,-3,-10);
    Equation eq2 = eq;
    Equation eq3(1,1,1);
    eq3 = eq2;
    std::cout << eq;



    return 0;

}
