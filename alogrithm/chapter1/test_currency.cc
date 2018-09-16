#include "currency.h"

int main(int argc, char * argv[]){
        currency a {positive, 2, 3};
        a.output();

        currency b {};
        b.setValue(-3.3);
        b.output();

        currency c = a.add(b);
        c.output();


        return 0;
}

