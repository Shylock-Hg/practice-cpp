#include "newCurrency.h"

newCurrency::newCurrency(signType sign,
                unsigned int dollars,
                unsigned int cents){
        setValue(sign, dollars, cents);
}
newCurrency::~newCurrency(){}

void newCurrency::setValue(
                signType sign, 
                unsigned int dollars, 
                unsigned int cents){
        this->cents = dollars*100 + cents;
        if(sign == negative){
                this->cents = - this->cents;
        }
}
void newCurrency::setValue(double value){
       if(value < 0){
                cents = static_cast<int64_t> ((value - 0.001)*100);
       }else{
                cents = static_cast<int64_t> ((value + 0.001)*100);
       }
}

/*
signType getSign() const;
unsigned int getDollars() const;
unsigned int getCents() const;
*/

newCurrency newCurrency::operator+(const newCurrency&x) const{
        newCurrency ret;
        ret.cents = cents + x.cents;
        return ret;
}
newCurrency newCurrency::operator-(const newCurrency&x) const{
        newCurrency z;
        z.cents = cents - x.cents;
        return z;
}
newCurrency & newCurrency::operator+=(const newCurrency&x){
        this->cents += x.cents;
        return *this;
}
newCurrency newCurrency::operator%(const unsigned int x) const{
        newCurrency z;
        z.cents = cents*x/100;
        return z;
}
newCurrency newCurrency::operator*(const double x) const{
        newCurrency z;
        z.cents = static_cast<int64_t>(cents*x);
        return z;
}
newCurrency newCurrency::operator/(const double x) const{
        newCurrency z;
        z.cents = static_cast<int64_t>(cents/x);
        return z;
}

void newCurrency::input(std::istream & in){
        char sign;
        char dollar;
        double value;
        
        if(sign == '-'){
                std::cout << "Reverse" << std::endl;
                value = -value;
        }

        setValue(value);
}

std::istream & operator>>(std::istream& in, newCurrency & x){
        x.input(in);
        return in;
}

void newCurrency::output(std::ostream & out) const{
        int64_t theCents = cents;
        if(theCents < 0){
                out << '-';
                theCents = -theCents;
        }

        int64_t dollars = theCents/100;
        int64_t c       = theCents%100;
        out << '$' << dollars << '.';
        if(c < 10) out << '0';
        out << c;
}
std::ostream & operator<<(std::ostream& out, const newCurrency & x){
        x.output(out);
        return out;
}

