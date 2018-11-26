/*! \brief 
 *  \author Shylock Hg
 *  \date 2018-11-26
 *  \email tcath2s@gmail.com
 * */

#include <iostream>

#include "./array_stack.hh"

int main(int argc, char * argv[]) {
        array_stack<int> a;
        a.push(10);
        
        std::cout << a.get_top() << std::endl;
        return 0;
}
