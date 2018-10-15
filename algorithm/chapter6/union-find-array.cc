#include <cstdint>
#include <memory>
#include <stdexcept>
#include <iterator>
#include <iostream>

class union_find {
protected:
        int * equivClass;
        std::size_t n;
public:
        union_find() : equivClass {nullptr}, n {0} {}

        explicit union_find(const std::size_t _n) :
                equivClass {new int[_n]}, n {_n} {
                for (std::size_t k=0; k<n; k++) {
                        equivClass[k] = k;
                }
        }

        //< copy
        union_find(const union_find & b) : equivClass {new int[b.n]}, n {b.n} {
                std::copy(b.equivClass, b.equivClass+b.n, equivClass);
        }

        //< move
        union_find(union_find && b) noexcept :
                        equivClass {b.equivClass}, n {b.n} {
                b.equivClass = nullptr;
                b.n = 0;
        }

        //< destructor
        ~union_find() {
                delete [] equivClass;
        }

        void unite(const int A, const int B) {
                for (std::size_t i=0; i<n; i++) {
                        if (equivClass[i] == B) {
                                equivClass[i] = A;
                        }
                }
        }
        
        int find(const std::size_t k) {
                if (k >= n) {
                        throw std::out_of_range("union find out of range!");
                }
                return equivClass[k];
        }
        
        std::ostream & output(std::ostream & out) const {
                copy(equivClass,
                        equivClass+n,
                        std::ostream_iterator<int> (out, " "));
                return out;
        }
};

std::ostream & operator << (std::ostream & out, const union_find & a) {
        return a.output(out);
}

int main (int argc, char * argv[]){
        union_find a(10);
        std::cout << a << std::endl;
        std::cout << "Class of 3 is " << a.find(3) << std::endl;

        a.unite(2, 3);
        std::cout << a << std::endl;
        std::cout << "Class of 3 is " << a.find(3) << std::endl;
        return 0;
}

