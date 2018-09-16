#include <cstdint>
#include <iostream>

#include "currency.h"

currency::currency(signType sign,
                unsigned int dollars,
                unsigned int cents){
        setValue(sign, dollars, cents);
}
currency::~currency(){}

void currency::setValue(
                signType sign, 
                unsigned int dollars, 
                unsigned int cents){
        this->sign = sign;
        this->dollars = dollars;
        if(cents < 100){
                this->cents = cents;
        }else{
                this->dollars += cents/100;
                this->cents    = cents%100;
        }
}
void currency::setValue(double value){
        this->sign = value > 0 ? positive : negative;
        value = value > 0 ? value : -value;
        this->dollars = static_cast<unsigned int> (value);
        this->cents = static_cast<unsigned int> ((value - this->dollars)*100);
        if(this->cents > 100){
                this->dollars += this->cents/100;
                this->cents    = this->cents%100;
        }
}

//signType getSign() const {return sign;}
//unsigned int getDollars() const {return dollars;}
//unsigned int getCents() const {return cents;}
signType currency::getSign() const {return sign;}
unsigned int currency::getDollars() const {return dollars;}
unsigned int currency::getCents() const {return cents;}

currency currency::add(const currency& a) const{
        currency ret;

        int64_t a1, a2, a3;
        a1 = dollars*100 + cents;
        if(negative == sign){
                a1 = -a1;
        }
        a2 = a.dollars*100 + a.cents;
        if(negative == a.sign){
                a2 = -a2;
        }

        a3 = a1 + a2;

        /*
        std::cout << std::endl;

        std::cout << dollars << ' ' << cents << std::endl;
        std::cout << a.dollars << ' ' << a.cents << std::endl;

        std::cout << "a1 is " << a1 << '.' << std::endl;
        std::cout << "a2 is " << a2 << '.' << std::endl;
        std::cout << "a3 is " << a3 << '.' << std::endl;
        */

        ret.setValue(a3/100.0f);

        return ret;
}
currency & currency::inc(const currency&x){
        *this = add(x);
        return *this;
}

void currency::output() const{
        if(sign == negative) std::cout << '-';
        std::cout << '$' << dollars << '.';
        if(cents < 10) std::cout << '0';
        std::cout << cents;
}


