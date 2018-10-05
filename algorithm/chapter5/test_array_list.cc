#include <memory>

#include "array_list.hh"

int main(int argc, char * argv[]){
        array_list<int> a {1, 2, 3};
        array_list<int> c {1, 2,};
        std::cout << (a == c) << std::endl;
        std::cout << a[1] << std::endl;
        std::cout << a << std::endl;
        a.insert(2, 4);
        std::cout << a << std::endl;

        array_list<int> b = std::move(a);
        std::cout << b << std::endl;

        b.erase(1);
        std::cout << b << std::endl;

        std::unique_ptr<linear_list<int>> l(
                dynamic_cast<linear_list<int>*> (
                                new array_list<int> {1, 2, 3} ));
        if (l) {
                std::cout << l->size() << std::endl;
                l->output(std::cout);
        }

        std::cout << l->find(5) << std::endl;

        std::cout << l->at(1) << std::endl;

        std::cout << l->empty() << std::endl;

        l->erase(1);

        std::unique_ptr<array_list<int>> ap(
                        dynamic_cast<array_list<int>*>(l.release()));
        if(ap){
                std::cout << "Convert success!" << std::endl;
                std::cout << *ap << std::endl;
        }

        //std::cout << l->at(1) << std::endl;
        //std::cout << l->size() << std::endl;

        return 0;
}

