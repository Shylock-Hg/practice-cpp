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

//#include "matrix.hh"

template <class __item__, std::size_t ROW, std::size_t COL>
class matrix_array {
private:
//        std::size_t row_;
//        std::size_t col_;
public:
        __item__* ele;
        matrix_array() : ele {new __item__[ROW*COL]} {};
        explicit matrix_array(std::initializer_list<__item__> list) :
                ele {new __item__[ROW*COL]} {
                        std::copy(list.begin(), list.end(), ele);
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
                return ele[row*COL + col];
        };
        matrix_array<__item__, ROW, COL> operator+ () const {
                matrix_array<__item__, ROW, COL> c;
                for (std::size_t i=0; i<ROW*COL; i++) {
                       c.ele[i] = +(ele[i]);
                }
                return c;
        };  //!< unary +
        matrix_array<__item__, ROW, COL> operator+ (
                        const matrix_array<__item__, ROW, COL>& b) const {
                /*
                if (row_ != b.row_ || col_ != b.col_) {
                        throw std::out_of_range("Matrix + out of range!\n");
                }
                */
                matrix_array<__item__, ROW, COL> c;
                for (std::size_t i=0; i<ROW*COL; i++) {
                        c.ele[i] = ele[i] + b.ele[i];
                }
                return c;
        };
        matrix_array<__item__, ROW, COL> operator- () const {
                matrix_array<__item__, ROW, COL> c;
                for (std::size_t i=0; i<ROW*COL; i++) {
                        c.ele[i] = -(ele[i]);
                }
                return c;
        };  //!< unary -
        matrix_array<__item__, ROW, COL> operator- (
                        const matrix_array<__item__, ROW, COL>& b) const {
                /*
                if (row_ != b.row_ || col_ != b.col_) {
                        throw std::out_of_range("Matrix + out of range!\n");
                }
                */
                matrix_array<__item__, ROW, COL> c;
                for (std::size_t i=0; i<ROW*COL; i++) {
                        c.ele[i] = ele[i] - b.ele[i];
                }
                return c;
        };
        template <std::size_t N>
        matrix_array<__item__, ROW, N> operator* (
                        const matrix_array<__item__, COL, N>& b) const {
                __item__ temp = 0;
                matrix_array<__item__, ROW, N> c;
                for (std::size_t i=0; i<ROW; i++) {
                        for (std::size_t j=0; j<N; j++) {
                                for (std::size_t k=0; k<COL; k++) {
                                        temp += (ele[i*COL+k] * b.ele[k*N+j]);
                                }
                                c.ele[i*N+j] = temp;
                                temp = 0;
                        }
                }
                return c;
        };
        //matrix_array<__item__>& operator+= (const __item__&);
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
std::ostream& operator<< (std::ostream& out, matrix_array<__item__, ROW, COL>& b) {
        return b.output(out);
}

#endif  //!< _TEMPLATE_H_

