#include "newCurrency.h"

int main(int argc, char * argv[]){
        newCurrency a {};
        newCurrency b {};
        std::cin >> b >> a;
        newCurrency c {};
        c = a + b;
        std::cout << "a + b = c is " <<
                a << " + " << b << " = " << c << std::endl;
        c = a - b;
        std::cout << "a - b = c is " <<
                a << " - " << b << " = " << c << std::endl;
        return 0;
}

