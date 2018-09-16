#ifndef __CURRENCY_H__
#define __CURRENCY_H__

enum signType {positive, negative};

class currency {
        // private:
        public:
                signType sign;
                unsigned int dollars;
                unsigned int cents;

        public:
                currency(signType sign = positive,
                                unsigned int dollars = 0,
                                unsigned int cents = 0);
                ~currency();

                void setValue(
                                signType sign, 
                                unsigned int dollars, 
                                unsigned int cents);
                void setValue(double value);

                signType getSign() const;
                unsigned int getDollars() const;
                unsigned int getCents() const;

                currency add(const currency&) const;
                currency & inc(const currency&);

                void output() const;
};

#endif
