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
        matrix_array<int, 3, 3> d = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        matrix_array<int, 3, 3> e = c - d;
        matrix_array<int, 3, 3> f = c + d;

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
        std::cout << e << std::endl;
        std::cout << f << std::endl;

        std::cout << -f << std::endl;
        std::cout << +f << std::endl;
        std::cout << a*(-b) << std::endl;

        std::cout << f(2, 1) << std::endl;

        std::cout << f.row() << "   " << f.col() << std::endl;

        matrix_array<float, 3, 3> g {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        std::cout << g << std::endl;
        std::cout << g.row() << "  " << g.col() << std::endl;

        std::cout << g-3 << std::endl;
        std::cout << g+3 << std::endl;

        matrix_array<float, 3, 3> h {1, 1, 1, 1, 1, 1, 1, 1, 1};
        std::cout << (g=h) << std::endl;
        std::cout << g << std::endl;

        std::cout << (g=g+1) << std::endl;
        std::cout << (g=g-1) << std::endl;

        std::cout << g*2 << std::endl;
        return 0;
}
