/*! \brief 
 *  \author Shylock Hg
 *  \date 2018-10-27
 *  \email tcath2s@gmail.com
 * */

#include "matrix_array.hh"

#include <iostream>

int main(int argc, char * argv[]) {
        matrix_array<int, 3, 2> a {1, 2, 3, 4, 5, 6};
        matrix_array<int, 2, 3> b {1, 2, 3, 4, 5, 6};
        matrix_array<int, 3, 3> c = a*b;

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
        return 0;
}
