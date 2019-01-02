/*! \brief 
 *  \author Shylock Hg
 *  \date 2018-10-31
 *  \email tcath2s@gmail.com
 * */

#ifndef _MATRIX_DIAGONAL_HH_
#define _MATRIX_DIAGONAL_HH_

#include <initializer_list>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <memory>
#include <algorithm>

template <class __item__, std::size_t ROW, std::size_t COL>
class matrix_diagonal {
private:
public:
        static constexpr std::size_t diagonal = std::min(ROW, COL);

        __item__* ele;  //!< just diagnal elements

        matrix_diagonal() : ele {new __item__[diagonal]} {};

        matrix_diagonal(std::initializer_list<__item__> list) :
                ele {new __item__[diagonal]} {
                if (std::min(ROW, COL) < list.size()) {
                        throw std::out_of_range("Initializer list out of range!\n");
                }
                std::copy(list.begin(), list.end(), ele);
        };

        matrix_diagonal(matrix_diagonal<__item__, ROW, COL>& b) :
                ele {new __item__[diagonal]} {
                std::copy(b.ele, b.ele+diagonal, ele);
        };

        matrix_diagonal(matrix_diagonal<__item__, ROW, COL>&& b) noexcept :
                ele {b.ele} {
                b.ele  = nullptr;
        };

        ~matrix_diagonal() {delete [] ele;};

        constexpr std::size_t row() const {return ROW;};
        constexpr std::size_t col() const {return COL;};

        __item__ operator()(std::size_t row, std::size_t col) const {
                if (row >= ROW || col >= COL) {
                        throw std::out_of_range("Matrix subscribe out of range!\n");
                }
                if (row == col) {
                        return ele[row];
                } else {
                        return 0;
                }
        };

        matrix_diagonal<__item__, ROW, COL> operator+ () const {
                matrix_diagonal<__item__, ROW, COL> c;
                for (std::size_t i=0; i<diagonal; i++) {
                       c.ele[i] = +(ele[i]);
                }
                return c;
        };  //!< unary +

        matrix_diagonal<__item__, ROW, COL> operator+ (const __item__ val) {
                matrix_diagonal<__item__, ROW, COL> c;
                for (std::size_t i=0; i<diagonal; i++) {
                        c.ele[i] = ele[i] + val;
                }
                return c;
        }  //!< !e implementation

        matrix_diagonal<__item__, ROW, COL> operator- () const {
                matrix_diagonal<__item__, ROW, COL> c;
                for (std::size_t i=0; i<diagonal; i++) {
                        c.ele[i] = -(ele[i]);
                }
                return c;
        };  //!< unary -

        matrix_diagonal<__item__, ROW, COL> operator- (const __item__ val) {
                matrix_diagonal<__item__, ROW, COL> c;
                for (std::size_t i=0; i<diagonal; i++) {
                        c.ele[i] = ele[i] - val;
                }
                return c;
        }  //!< !e implementation

        matrix_diagonal<__item__, ROW, COL> operator* (const __item__ val) {
                matrix_diagonal<__item__, ROW, COL> c;
                for (std::size_t i=0; i<diagonal; i++) {
                        c.ele[i] = ele[i] * val;
                }
                return c;
        }

        matrix_diagonal<__item__, ROW, COL>& operator= (const matrix_diagonal<__item__, ROW, COL>& b) {
                std::copy(b.ele, b.ele+diagonal, ele);
                return *this;
        }

        matrix_diagonal<__item__, COL, ROW> transpose() const {
                matrix_diagonal<__item__, COL, ROW> c;
                std::copy(ele, ele+diagonal, c.ele);
                return c;
        }

        std::ostream& output (std::ostream& out) const {
                for (std::size_t i=0; i<ROW; i++) {
                        for (std::size_t j=0; j<COL; j++) {
                                if (i >= diagonal || j >= diagonal) {
                                        out << 0 << "  ";
                                } else if (i == j) {
                                        out << ele[i] << "  ";
                                } else {
                                        out << 0 << "  ";
                                }
                        }
                        out << std::endl;
                }
                return out;
        }
};

template <class __item__, std::size_t ROW, std::size_t COL>
std::ostream& operator<< (std::ostream& out, matrix_diagonal<__item__, ROW, COL> b) {
        return b.output(out);
}

template <class __item__, std::size_t ROW, std::size_t COL>
matrix_diagonal<__item__, ROW, COL> operator+ (
                const matrix_diagonal<__item__, ROW, COL>& a,
                const matrix_diagonal<__item__, ROW, COL>& b) {
        matrix_diagonal<__item__, ROW, COL> c;
        for (std::size_t i=0; i<matrix_diagonal<__item__, ROW, COL>::diagonal; i++) {
                c.ele[i] = a.ele[i] + b.ele[i];
        }
        return c;
};

template <class __item__, std::size_t ROW, std::size_t COL>
matrix_diagonal<__item__, ROW, COL> operator- (
                const matrix_diagonal<__item__, ROW, COL>& a,
                const matrix_diagonal<__item__, ROW, COL>& b) {
        matrix_diagonal<__item__, ROW, COL> c;
        for (std::size_t i=0; i<matrix_diagonal<__item__, ROW, COL>::diagonal; i++) {
                c.ele[i] = a.ele[i] - b.ele[i];
        }
        return c;
};

template <class __item__, std::size_t ROW, std::size_t N, std::size_t COL>
matrix_diagonal<__item__, ROW, COL> operator* (
                const matrix_diagonal<__item__, ROW, N>& a,
                const matrix_diagonal<__item__, N, COL>& b) {
        __item__ temp = 0;
        matrix_diagonal<__item__, ROW, COL> c;
        for (std::size_t i=0; i<std::min(std::min(ROW, N), COL); i++) {
                c.ele[i] = a.ele[i]*b.ele[i];
        }
        return c;
};

#endif  //!< _MATRIX_DIAGONAL_HH_

