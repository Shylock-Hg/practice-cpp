/*! \brief 
 *  \author Shylock Hg
 *  \date 2018-11-02
 *  \email tcath2s@gmail.com
 * */

#include "matrix_spare.hh"

int main (int argc, char * argv[]) {
        matrix_spare<int, 3, 2> a {{0, 0, 1}, {0, 1, 2}};
        matrix_spare<int, 3, 2> b {{0, 0, 1}, {0, 2, 3}};
        std::cout << "a(0, 0) is " << a(0, 0) << std::endl;
        std::cout << a << std::endl << (a+b) << std::endl << (a-b) << std::endl;
        matrix_spare<int, 2, 3> c {{0, 0, -1}, {0, 2, -2}};
        std::cout << (+c) << std::endl << (-a) << std::endl;
        
        std::cout << a+3 << std::endl << a-3 << std::endl;

        matrix_spare<int, 3UL, 2UL> d {{0, 0, 1}, {0, 1, 2}, {0, 2, 3},
                {1, 0, 4}, {1, 1, 5}, {1, 2, 6}};
        std::cout << "d.transpose() is " << std::endl << d.transpose() << std::endl;
        matrix_spare<int, 2, 3> e {{0, 0, 1}, {0, 1, 2}, {0, 2, 3},
                {1, 0, 4}, {1, 1, 5}, {1, 2, 6}};
        std::cout << "Multipy is " << std::endl << (d*e) << std::endl;

        return 0;
}
