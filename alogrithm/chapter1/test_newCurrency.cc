#include "newCurrency.h"

int main(int argc, char * argv[]){
        newCurrency a {};
        newCurrency b {};
        std::cin >> b >> a;
        a.setValue(3.3);
        b.setValue(-2.1);
        newCurrency c {};

        c = a + b;
        std::cout << "a + b = c is " <<
                a << " + " << b << " = " << c << std::endl;

        c = a - b;
        std::cout << "a - b = c is " <<
                a << " - " << b << " = " << c << std::endl;

        std::cout << "a%30 a is " << a%30 << std::endl;

        std::cout << "a*-3.3 is " << a*-3.3 << std::endl;
        return 0;
}

