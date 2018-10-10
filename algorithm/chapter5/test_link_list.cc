#include "link_list.hh"

int main (int argc, char * argv[]){
        link_list<int> a;

        std::cout << a.empty() << std::endl;
        std::cout << "Size is " << a.size() << std::endl;
        std::cout << "Find 7 is " << a.find(7) << std::endl;

        a.insert(0, 0);
        a.insert(1, 1);
        a.insert(2, 2);
        a.insert(0, 0);
        a.insert(1, 1);

        std::cout << a.at(1) << std::endl;
        std::cout << a.at(0) << std::endl;
        std::cout << a.at(4) << std::endl;
        // std::cout << a.at(-1) << std::endl;
        // std::cout << a.at(5) << std::endl;

        std::cout << a.empty() << std::endl;       
        std::cout << "Size is " << a.size() << std::endl;

        std::cout << "Find 2 is " << a.find(2) << std::endl;
        std::cout << "Find 7 is " << a.find(7) << std::endl;

        a.erase(0);
        std::cout << "Size is " << a.size() << std::endl;
        a.erase(3);
        std::cout << "Size is " << a.size() << std::endl;
        a.erase(1);
        std::cout << "Size is " << a.size() << std::endl;

        std::cout << a << std::endl;

        auto b = std::move(a);
        b.insert(2, 2);
        b.insert(3, 3);
        std::cout << b << std::endl;

        b.push_back(11);
        std::cout << b << std::endl;
        std::cout << b.size() << std::endl;
        return 0;
}

