/*! \brief 
 *  \author Shylock Hg
 *  \date 2018-11-02
 *  \email tcath2s@gmail.com
 * */

#ifndef _MATRIX_SPARE_HH_
#define _MATRIX_SPARE_HH_

#include <initializer_list>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <memory>
#include <list>
#include <algorithm>

template <class __item__, std::size_t ROW, std::size_t COL>
class matrix_spare {
private:
public:
        struct value_type {
                std::size_t row = 0;
                std::size_t col = 0;
                __item__ value = 0;
/*
                value_type(const std::size_t row_, std::size_t col_, __item__ value_) : row {row_}, col {col_}, value {value_} {};
                explicit value_type(const typename matrix_spare<__item__, COL, ROW>::value_type& b) : row {b.col}, col {b.row}, value {b.value} {
                };
                typename matrix_spare<__item__, ROW, COL>::value_type operator= (const typename matrix_spare<__item__, COL, ROW>::value_type& a) {
                        matrix_spare<__item__, ROW, COL> c;
                        c.row   = a.col;
                        c.col   = a.row;
                        c.value = a.value;
                        return 0;
                };
*/
        };
        std::list<value_type> ele;
        matrix_spare() = default;
        explicit matrix_spare(std::size_t n) : ele {std::list<value_type>(n)} {}
        matrix_spare(std::initializer_list<value_type> l) :
                ele {std::list<value_type> (l.size())} {
                if (ROW*COL < l.size()) {
                        throw std::out_of_range("Initializer list out of range!\n");
                }
                std::copy(l.begin(), l.end(), ele.begin());
        };
        matrix_spare(const matrix_spare<__item__, ROW, COL>& b) :
                ele {b.ele} {};
        matrix_spare(matrix_spare<__item__, ROW, COL>&& b) noexcept :
                ele {std::move(b.ele)} {};
        ~matrix_spare() = default;

        constexpr std::size_t row() const {return ROW;};
        constexpr std::size_t col() const {return COL;};

        __item__ operator()(std::size_t row, std::size_t col) const {
                if (row >= ROW || col >= COL) {
                        throw std::out_of_range("Matrix subscribe out of range!\n");
                }
                const auto rc = std::find_if(ele.begin(),
                        ele.end(),
                        [row, col](matrix_spare<__item__, ROW, COL>::value_type a) -> bool {
                        return a.row == row && a.col == col;
                });
                if (rc != ele.end()) {
                        return rc->value;
                } else {
                        return 0;
                }
        };

        matrix_spare<__item__, ROW, COL> operator+ () const {
                matrix_spare<__item__, ROW, COL> c(*this);
                for (auto & it : c.ele) {
                        it.value = (it.value < 0 ? (-it.value) : (+it.value));
                }
                return c;
        };  //!< unary +

        matrix_spare<__item__, ROW, COL> operator+ (const __item__ val) {
                matrix_spare<__item__, ROW, COL> c(*this);
                for (auto & it : c.ele) {
                        it.value += val;
                }
                return c;
        }  //!< error implementation

        matrix_spare<__item__, ROW, COL> operator- () const {
                matrix_spare<__item__, ROW, COL> c(*this);
                for (auto & it : c.ele) {
                        it.value = (-it.value);
                }
                return c;
        };  //!< unary -

        matrix_spare<__item__, ROW, COL> operator- (const __item__ val) {
                matrix_spare<__item__, ROW, COL> c(*this);
                for (auto & it : c.ele) {
                        it.value -= val;
                }
                return c;
        }  //!< error implementation

        matrix_spare<__item__, ROW, COL> operator* (const __item__ val) {
                matrix_spare<__item__, ROW, COL> c(*this);
                for (auto & it : c.ele) {
                        it.value *= val;
                }
                return c;
        }

        matrix_spare<__item__, ROW, COL>& operator= (const matrix_spare<__item__, ROW, COL>& b) {
                ele = b.ele;
                return *this;
        }

        matrix_spare<__item__, COL, ROW> transpose() const {
                matrix_spare<__item__, COL, ROW> c(ele.size());
                auto ait = c.ele.begin();
                auto bit = ele.begin();
                for (std::size_t i=0; i<ele.size(); i++) {
                        ait->row   = bit->col;
                        ait->col   = bit->row;
                        ait->value = bit->value;
                        ait = std::next(ait);
                        bit = std::next(bit);
                }
                return c;
        }

        std::ostream& output (std::ostream& out) const {
                for (const auto it : ele) {
                        out << it.row << "  " << it.col << "  " << it.value << std::endl;
                }
                return out;
        }
};

template <class __item__, std::size_t ROW, std::size_t COL>
std::ostream& operator<< (std::ostream& out, matrix_spare<__item__, ROW, COL> b) {
        return b.output(out);
}

template <class __item__, std::size_t ROW, std::size_t COL>
matrix_spare<__item__, ROW, COL> operator+ (
                const matrix_spare<__item__, ROW, COL>& a,
                const matrix_spare<__item__, ROW, COL>& b) {
        matrix_spare<__item__, ROW, COL> c;
        //!< push the set -- a and b
        for (const auto& it : a.ele) {
                auto rc = std::find_if(b.ele.begin(), b.ele.end(), [it](typename matrix_spare<__item__, ROW, COL>::value_type d) -> bool {
                        return it.row == d.row && it.col == d.col;
                });
                if (rc != b.ele.end()) {
                        typename matrix_spare<__item__, ROW, COL>::value_type e = {it.row, it.col, it.value+rc->value};
                        if (e.value != 0) {
                                c.ele.push_back(e);
                        }
                } else {
                        typename matrix_spare<__item__, ROW, COL>::value_type e = {it.row, it.col, it.value};
                        if (e.value != 0) {
                                c.ele.push_back(e);
                        }
                }
        }
        
        //!< push the set -- b except a
        for (const auto& it : b.ele) {
                auto rc = std::find_if(a.ele.begin(), a.ele.end(), [it](typename matrix_spare<__item__, ROW, COL>::value_type d) -> bool {
                        return it.row == d.row && it.col == d.col;
                });
                if (rc == a.ele.end()) {
                        typename matrix_spare<__item__, ROW, COL>::value_type e = {it.row, it.col, it.value};
                        if (e.value != 0) {
                                c.ele.push_back(e);
                        }
                }
        }
        return c;
};

template <class __item__, std::size_t ROW, std::size_t COL>
matrix_spare<__item__, ROW, COL> operator- (
                const matrix_spare<__item__, ROW, COL>& a,
                const matrix_spare<__item__, ROW, COL>& b) {
        matrix_spare<__item__, ROW, COL> c;
        //!< push the set -- a and b
        for (const auto& it : a.ele) {
                auto rc = std::find_if(b.ele.begin(), b.ele.end(), [it](typename matrix_spare<__item__, ROW, COL>::value_type d) -> bool {
                        return it.row == d.row && it.col == d.col;
                });
                if (rc != b.ele.end()) {
                        typename matrix_spare<__item__, ROW, COL>::value_type e = {it.row, it.col, it.value-rc->value};
                        if (e.value != 0) {
                                c.ele.push_back(e);
                        }
                } else {
                        typename matrix_spare<__item__, ROW, COL>::value_type e = {it.row, it.col, it.value};
                        if (e.value != 0) {
                                c.ele.push_back(e);
                        }
                }
        }
        
        //!< push the set -- b except a
        for (const auto& it : b.ele) {
                auto rc = std::find_if(a.ele.begin(), a.ele.end(), [it](typename matrix_spare<__item__, ROW, COL>::value_type d) -> bool {
                        return it.row == d.row && it.col == d.col;
                });
                if (rc == a.ele.end()) {
                        typename matrix_spare<__item__, ROW, COL>::value_type e = {it.row, it.col, -it.value};
                        if (e.value != 0) {
                                c.ele.push_back(e);
                        }
                }
        }
        return c;
};

template <class __item__, std::size_t ROW, std::size_t N, std::size_t COL>
matrix_spare<__item__, ROW, COL> operator* (
                const matrix_spare<__item__, ROW, N>& a,
                const matrix_spare<__item__, N, COL>& b) {
        __item__ temp = 0;
        matrix_spare<__item__, ROW, COL> c;
        __item__ val = 0;
        for (std::size_t i=0; i<ROW; i++) {
                for (std::size_t j=0; j<COL; j++) {
                        for ( std::size_t k=0; k<N; k++) {
                                auto left = std::find_if(a.ele.begin(), 
                                        a.ele.end(),
                                        [i, k](typename matrix_spare<__item__, ROW, N>::value_type d) -> bool {
                                        return d.row == i && d.col == k;
                                });
                                auto right = std::find_if(b.ele.begin(),
                                        b.ele.end(),
                                        [k, j](typename matrix_spare<__item__, N, COL>::value_type d) -> bool {
                                        return d.row == k && d.col == j;
                                });
                                if (left != a.ele.end() && right != b.ele.end()) {
                                        val += (left->value*right->value);
                                }
                        }
                        typename matrix_spare<__item__, ROW, COL>::value_type e = {i, j, val};
                        if (0 != e.value) {
                                c.ele.push_back(e);
                        }
                        val = 0;
                }
        }
        return c;
};

#endif  //!< _MATRIX_SPARE_HH_

