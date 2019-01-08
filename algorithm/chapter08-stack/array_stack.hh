/*! \brief 
 *  \author Shylock Hg
 *  \date 2018-11-26
 *  \email tcath2s@gmail.com
 * */

#ifndef _ARRAY_STACK_HH_
#define _ARRAY_STACK_HH_

#include <memory>
#include <stdexcept>

#include "./stack.hh"

template <class ITEM>
class array_stack : public stack<ITEM> {
typedef ITEM value_type;
typedef ITEM* pointer_type;
typedef ITEM& reference_type;
typedef const ITEM& const_reference_type;
private:
        pointer_type ele;
        std::size_t cap;
        std::size_t top;  //!< point to empty placeholder
public:
        array_stack() : ele {nullptr}, cap {0}, top{0} {}
        explicit array_stack(std::size_t _cap) :
                ele {new value_type[_cap]},
                cap {_cap}, top {0} {}
        //!< copy constructor
        explicit array_stack(const array_stack<value_type>& b) :
                ele {new value_type[b.cap]}, cap {b.cap}, top {b.top} {
                std::copy(b.ele, b.ele+b.cap, ele);
        }
        //!< move constructor
        explicit array_stack(const array_stack<value_type>&& b) :
                ele {b.ele}, cap {b.cap}, top {b.top} {
                b.ele = nullptr;
                b.cap = 0;
                b.top = 0;
        }
        ~array_stack() {delete [] ele;}

        bool empty() const {
                return 0 == top;
        }

        std::size_t size() const {
                return top;
        }
        reference_type get_top() const {
                if (cap <= (top-1)) {
                        throw std::out_of_range(
                                "Err: Stack top out of range!\n");
                }
                return ele[top-1];
        }
        value_type pop() {
                if (0 < top) {
                        return ele[--top];
                } else {
                        throw std::out_of_range(
                                "Err: Stack pop out of range!\n");
                }
        }
        void push(const_reference_type item) {
                if (cap <= top) {
                        delete [] ele;
                        ele = new value_type[cap*2+10];  //!< +10 ant 0 cap
                        cap = (cap*2+10);
                }
                ele[top++] = item;
        }
};

#endif  //!< _ARRAY_STACK_HH_

