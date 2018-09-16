#include "newCurrency.h"

int main(int argc, char * argv[]){
        newCurrency a {};
        newCurrency b {};
        b.setValue(2.3);
        newCurrency c {};
        c = a + b;
        std::cout << "a + b = c is " << a << " + " << b << " = " << c << std::endl;
        return 0;
}

