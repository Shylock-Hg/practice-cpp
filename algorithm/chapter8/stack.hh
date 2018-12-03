/*! \brief 
 *  \author Shylock Hg
 *  \date 2018-11-26
 *  \email tcath2s@gmail.com
 * */

#ifndef _STACK_HH_
#define _STACK_HH_

#include <type_traits>

template <class ITEM>
class stack {
public:
        typedef ITEM value_type;
        typedef ITEM* pointer_type;
        typedef ITEM& reference_type;
        typedef const ITEM& const_reference_type;

        virtual bool empty() const = 0;
        virtual std::size_t size() const = 0;
        virtual reference_type get_top() const = 0;
        virtual value_type pop() = 0;
        virtual void push(const_reference_type item) = 0;
};

#endif  //!< _STACK_HH_

