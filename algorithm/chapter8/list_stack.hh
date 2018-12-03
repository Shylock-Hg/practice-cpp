/*! \brief 
 *  \author Shylock Hg
 *  \date 2018-12-01
 *  \email tcath2s@gmail.com
 * */

#ifndef _LIST_STACK_HH_
#define _LIST_STACK_HH_

#include <stdexcept>

#include "stack.hh"

template <class ITEM>
class list_stack : stack<ITEM> {
public:
        template <class _ITEM>
        struct node {
                typedef _ITEM value_type;
                typedef _ITEM* pointer_type;
                typedef _ITEM& reference_type;
                typedef const _ITEM& const_reference_type;

                node<value_type>* prev;
                node<value_type>* next;
                value_type value;
        };
        typedef ITEM value_type;
        typedef ITEM* pointer_type;
        typedef ITEM& reference_type;
        typedef const ITEM& const_reference_type;
private:
        node<value_type>* top;
        std::size_t count;
public:

        // default -- at leat one node for simpfy operations
        list_stack() : top {new node<value_type>}, count {0} {}
        // move
        list_stack(list_stack<value_type>&& b) :
                top {b.top}, count {b.count} {
                b.top = nullptr;
                b.count = 0;
        }
        ~list_stack() {
                node<value_type>* temp = top;
                while(nullptr != temp) {
                        top = top->prev;
                        delete temp;
                        temp = top;
                }
        }
        
        bool empty() const {
                return 0 == count;
        }
        std::size_t size() const {
                return count;
        }
        reference_type get_top() const {
                return (top->value);
        }
        value_type pop() {
                if (0 == count) {
                        throw std::out_of_range("List stack pop out of range!\n");
                }
                node<value_type>* temp = top;
                value_type temp_value = top->value;
                top = top->prev;
                top->next = nullptr;
                delete temp;
                count--;
                return temp_value;
        }
        void push(const_reference_type item) {
                top->next = new node<value_type>;
                top->next->prev = top;
                top->next->next = nullptr;
                top = top->next;
                top->value = item;
                count++;
        }
};

#endif  //!< _LIST_STACK_HH_

