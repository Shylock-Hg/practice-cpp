/*! \brief 
 *  \author Shylock Hg
 *  \date 2018-10-27
 *  \email tcath2s@gmail.com
 * */

#ifndef _MATRIX_ARRAY_HH_
#define _MATRIX_ARRAY_HH_

#include <initializer_list>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <memory>

template <class __item__, std::size_t ROW, std::size_t COL>
class matrix_array {
private:
public:
        __item__* ele;
        matrix_array() : ele {new __item__[ROW*COL]} {};
        matrix_array(std::initializer_list<__item__> list) :
                ele {new __item__[ROW*COL]} {
                if (ROW*COL < list.size()) {
                        throw std::out_of_range("Initializer list out of range!\n");
                }
                std::copy(list.begin(), list.end(), ele);
        };
        matrix_array(std::initializer_list<std::initializer_list<__item__>> list) :
                ele {new __item__[ROW*COL]} {
                if (ROW < list.size()) {
                        throw std::out_of_range("Initializer list row out of range!\n");
                }
                std::size_t i_row = 0;
                for (const auto & row : list) {
                        if (COL < row.size()) {
                                throw std::out_of_range("Initializer list col out of range!\n");
                        }
                        std::copy(row.begin(), row.end(), ele+(i_row++)*COL);
                }
        };
        matrix_array(matrix_array<__item__, ROW, COL>& b) :
                ele {new __item__[ROW*COL]} {
                std::copy(b.ele, b.ele+ROW*COL, ele);
        };
        matrix_array(matrix_array<__item__, ROW, COL>&& b) noexcept :
                ele {b.ele} {
                b.ele  = nullptr;
        };
        ~matrix_array() {delete [] ele;};

        constexpr std::size_t row() const {return ROW;};
        constexpr std::size_t col() const {return COL;};

        __item__& operator()(std::size_t row, std::size_t col) const {
                if (row >= ROW || col >= COL) {
                        throw std::out_of_range("Matrix subscribe out of range!\n");
                }
                return ele[row*COL + col];
        };

        matrix_array<__item__, ROW, COL> operator+ () const {
                matrix_array<__item__, ROW, COL> c;
                for (std::size_t i=0; i<ROW*COL; i++) {
                       c.ele[i] = +(ele[i]);
                }
                return c;
        };  //!< unary +

        matrix_array<__item__, ROW, COL> operator+ (const __item__ val) {
                matrix_array<__item__, ROW, COL> c;
                for (std::size_t i=0; i<ROW*COL; i++) {
                        c.ele[i] = ele[i] + val;
                }
                return c;
        }

        matrix_array<__item__, ROW, COL> operator- () const {
                matrix_array<__item__, ROW, COL> c;
                for (std::size_t i=0; i<ROW*COL; i++) {
                        c.ele[i] = -(ele[i]);
                }
                return c;
        };  //!< unary -

        matrix_array<__item__, ROW, COL> operator- (const __item__ val) {
                matrix_array<__item__, ROW, COL> c;
                for (std::size_t i=0; i<ROW*COL; i++) {
                        c.ele[i] = ele[i] - val;
                }
                return c;
        }

        matrix_array<__item__, ROW, COL> operator* (const __item__ val) {
                matrix_array<__item__, ROW, COL> c;
                for (std::size_t i=0; i<ROW*COL; i++) {
                        c.ele[i] = ele[i] * val;
                }
                return c;
        }

        matrix_array<__item__, ROW, COL>& operator= (const matrix_array<__item__, ROW, COL>& b) {
                std::copy(b.ele, b.ele+ROW*COL, ele);
                return *this;
        }

        std::ostream& output (std::ostream& out) const {
                for(std::size_t i=0; i<ROW; i++) {
                        std::copy(ele+(i*COL),
                                        ele+((i+1)*COL),
                                        std::ostream_iterator<__item__>(out, "  "));
                        out << std::endl;
                }
                return out;
        }
};

template <class __item__, std::size_t ROW, std::size_t COL>
std::ostream& operator<< (std::ostream& out, matrix_array<__item__, ROW, COL> b) {
        return b.output(out);
}

template <class __item__, std::size_t ROW, std::size_t COL>
matrix_array<__item__, ROW, COL> operator+ (
                const matrix_array<__item__, ROW, COL>& a,
                const matrix_array<__item__, ROW, COL>& b) {
        matrix_array<__item__, ROW, COL> c;
        for (std::size_t i=0; i<ROW*COL; i++) {
                c.ele[i] = a.ele[i] + b.ele[i];
        }
        return c;
};

template <class __item__, std::size_t ROW, std::size_t COL>
matrix_array<__item__, ROW, COL> operator- (
                const matrix_array<__item__, ROW, COL>& a,
                const matrix_array<__item__, ROW, COL>& b) {
        matrix_array<__item__, ROW, COL> c;
        for (std::size_t i=0; i<ROW*COL; i++) {
                c.ele[i] = a.ele[i] - b.ele[i];
        }
        return c;
};

template <class __item__, std::size_t ROW, std::size_t N, std::size_t COL>
matrix_array<__item__, ROW, COL> operator* (
                const matrix_array<__item__, ROW, N>& a,
                const matrix_array<__item__, N, COL>& b) {
        __item__ temp = 0;
        matrix_array<__item__, ROW, COL> c;
        for (std::size_t i=0; i<ROW; i++) {
                for (std::size_t j=0; j<COL; j++) {
                        for (std::size_t k=0; k<N; k++) {
                                temp += (a.ele[i*N+k] * b.ele[k*COL+j]);
                        }
                        c.ele[i*COL+j] = temp;
                        temp = 0;
                }
        }
        return c;
};

#endif  //!< _TEMPLATE_H_

