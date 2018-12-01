/*! \brief 
 *  \author Shylock Hg
 *  \date 2018-11-26
 *  \email tcath2s@gmail.com
 * */

#include <iostream>

#include "./array_stack.hh"

int main(int argc, char * argv[]) {
        array_stack<int> a;
        std::cout << a.empty() << std::endl;
        a.push(10);
        a.push(11);
        std::cout << a.empty() << std::endl;
        std::cout << a.size() << std::endl;

        std::cout << a.get_top() << std::endl;
        std::cout << a.pop() << std::endl;
        std::cout << a.size() << std::endl;

        a.push(11);
        std::cout << a.size() << std::endl;
        a.push(12);
        std::cout << a.size() << std::endl;
        std::cout << a.get_top() << std::endl;

        return 0;
}
