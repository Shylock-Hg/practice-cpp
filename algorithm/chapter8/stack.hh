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
        virtual bool empty() const = 0;
        virtual std::size_t size() const = 0;
        virtual ITEM& get_top() const = 0;
        virtual ITEM pop() = 0;
        virtual void push(const ITEM& item) = 0;
};

#endif  //!< _STACK_HH_

