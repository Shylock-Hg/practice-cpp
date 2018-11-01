/*! \brief 
 *  \author Shylock Hg
 *  \date 2018-10-31
 *  \email tcath2s@gmail.com
 * */

#include "matrix_diagonal.hh"

int main (int argc, char * argv[]) {
        matrix_diagonal<int, 3, 2> a {1, 2};
        // matrix_diagonal<int, 2, 3> b {1, 2, 3, 4};  //!< throw exception
        matrix_diagonal<int, 2, 3> b {1, 2};
        std::cout << a << std::endl;
        std::cout << a*b << std::endl;

        matrix_diagonal<float, 3, 2> c {1, 2};
        matrix_diagonal<float, 2, 5> d {1, 2};
        std::cout << c*d << std::endl;
        std::cout << c(1, 1) << "  " << c(0, 1) << std::endl;
        std::cout << c.transpose() << std::endl;
        // std::cout << c(2, 2) << std::endl;  //!< throw exception

        matrix_diagonal<int, 1, 2> e {1};
        matrix_diagonal<int, 2, 1> f {3};
        std::cout << e*f << std::endl;
        std::cout << -e << (+(-e)) << std::endl;

        matrix_diagonal<int, 1, 2> g {1};
        matrix_diagonal<int, 1, 2> h {2};
        std::cout << (g-h) << (g+h) << std::endl;
        std::cout << g.transpose() << std::endl;

        matrix_diagonal<int, 1, 2> i {-1};
        std::cout << (+i) << std::endl;
        std::cout << i.row() << "  " << i.col() << std::endl;
        return 0;
}
