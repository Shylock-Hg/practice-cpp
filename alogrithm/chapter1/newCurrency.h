#include <cstdint>
#include <iostream>

#ifndef __NEW_CURRENCY_H__
#define __NEW_CURRENCY_H__

enum signType {positive, negative};

class newCurrency {
        // private:
        public:
                int64_t cents;

        public:
                newCurrency(signType sign = positive,
                                unsigned int dollars = 0,
                                unsigned int cents = 0);
                ~newCurrency();

                void setValue(
                                signType sign, 
                                unsigned int dollars, 
                                unsigned int cents);
                void setValue(double value);
/*
                signType getSign() const;
                unsigned int getDollars() const;
                unsigned int getCents() const;
*/

                newCurrency operator+(const newCurrency&) const;
                newCurrency operator-(const newCurrency&) const;
                newCurrency & operator+=(const newCurrency&);
                newCurrency operator%(const unsigned int x) const;
                newCurrency operator*(const double x) const;

                void input(std::istream & in);
                void output(std::ostream & out) const;
};

std::istream & operator>>(std::istream& in, newCurrency & x);
std::ostream & operator<<(std::ostream& out, const newCurrency & x);

#endif

