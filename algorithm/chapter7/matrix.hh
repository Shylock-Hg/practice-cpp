/*! \brief 
 *  \author Shylock Hg
 *  \date 2018-10-27
 *  \email tcath2s@gmail.com
 * */

#ifndef _MATRIX_HH_
#define _MATRIX_HH_

#include <type_traits>

template <class __item__>
class matrix {
public:
        matrix(std::size_t, std::size_t) = 0;
        matrix() = 0;
        matrix(matrix<__item__>&) = 0;
        virtual ~matrix() = 0;

        virtual std::size_t row() const = 0;
        virtual std::size_t col() const = 0;

        virtual __item__& operator()(std::size_t i, std::size_t j) const = 0;
        virtual matrix<__item__>& operator= (const matrix<__item__>&) = 0;
        virtual matrix<__item__>& operator+ () const = 0;  //!< unary +
        virtual matrix<__item__>& operator+ (const matrix<__item__>&) const = 0;
        virtual matrix<__item__>& operator- () const = 0;  //!< unary -
        virtual matrix<__item__>& operator- (const matrix<__item__>&) const = 0;
        virtual matrix<__item__>& operator* (const matrix<__item__>&) const = 0;
        virtual matrix<__item__>& operator+= (const __item__&) = 0;
};

#endif  //!< _TEMPLATE_H_

