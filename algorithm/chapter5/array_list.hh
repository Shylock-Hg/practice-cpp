#include "linear_list.hh"

#include <stdexcept>
#include <initializer_list>
#include <iterator>

#ifndef _ARRAY_LIST_H_
#define _ARRAY_LIST_H_

template <class __item__>
class array_list : public linear_list<__item__> {
private:
        __item__* array;
        size_t count;
public:
//< iterator
        class iterator {
                public:
                        //<
                        typedef std::bidirectional_iterator_tag iterator_category_t;
                        typedef __item__ value_t;
                        typedef std::ptrdiff_t difference_t;
                        typedef __item__* pointer_t;
                        typedef __item__& reference_t;

                        //< constructor 
                        iterator() {pointer = nullptr;}
                        explicit iterator(pointer_t init) {pointer = init;}

                        //< dereference operator
                        reference_t operator*() const {return *pointer;}
                        pointer_t operator->() const {return pointer;}
                        
                        //< succ
                        iterator& operator++() {return ++pointer, *this;}
                        iterator operator++(int) {
                                iterator temp = *this;
                                ++pointer;
                                return temp;
                        }

                        //< dec
                        iterator& operator--() {return --pointer, *this;}
                        iterator operator--(int) {
                                iterator temp = *this;
                                --pointer;
                                return temp;
                        }

                        //< equl
                        bool operator!=(const iterator right) const {
                                return pointer != right.pointer;
                        }
                        bool operator==(const iterator right) const {
                                return pointer == right.pointer;
                        }

                protected:
                        pointer_t pointer;
        };

        //< plain
        array_list() : linear_list<__item__>(), array {nullptr}, count {0} {}
        //< 
        explicit array_list(std::initializer_list<__item__> list) :
                linear_list<__item__>(),
                array {new __item__[list.size()]},
                count {static_cast<size_t>(list.size())} {
                        std::copy(list.begin(), list.end(), array);
                }
        //< copy
        array_list(const array_list<__item__> & s) :
                linear_list<__item__>(),
                array { new __item__[s.size()] },
                count { s.size() } {
                std::copy(s.begin(), s.end(), array);
        }
        //< move
        array_list(array_list<__item__> && s) noexcept :
                count { s.size() } {
                array = s.array;
                s.array = nullptr;
        }
        ~array_list() {
                delete [] array;
        }

        iterator begin() {
                iterator item(array);
                return item;
        }
        const iterator begin() const {
                iterator item(array);
                return item;
        
        }
        iterator end() {
                iterator item(array+count);
                return item;
        }
        const iterator end() const {
                iterator item(array+count);
                return item;
        }
        /*
        __item__ * begin() {
                return array+0;
        }
        const __item__ * begin() const {
                return array+0;
        }
        __item__ * end() {
                return array+count;
        }
        const __item__ * end() const {
                return array+count;
        }
        */

         bool empty() const{return static_cast<bool>(!count);}
         size_t size() const{return count;}
         __item__& at(size_t i) const{
                if(i >= count){
                        throw std::out_of_range("Out of range!\n");
                }
                return array[i];
        }
         __item__& operator[](size_t i) const {
                return at(i);
         }
         bool operator==(array_list & l) const {
                if(this->size() != l.size())
                        return false;
                size_t min = this->size();
                for(size_t i=0; i<min; i++){
                        if((*this)[i] != l[i])
                                return false;
                }
                return true;
         }
         int find(const __item__& value) const {
                for(int i=0; i<count; i++){
                        if(array[i] == value){
                                return i;
                        }
                }
                return -1;
        }
         void erase(size_t i) {
                if(i >= count){
                        throw std::out_of_range("Out of range!\n");
                }
                for(int j=i; j<count-1; j++) {
                        array[j] = array[j+1];
                }
                count--;
        }
         void insert(size_t i, const __item__& value) {
                if(i >= count+1){
                        throw std::out_of_range("Out of range!\n");
                }
                auto * p = new __item__[count+1];
                std::copy(array, array+i, p);
                *(p+i) = value;
                std::copy(array+i, array+count, p+i+1);
                delete [] array;
                array = p;
                count++;
         }
         void output(std::ostream& out) const {
                 std::copy(
                         array,
                         array+count,
                         std::ostream_iterator<__item__>(out , " "));
         }

};

template <class __IO__>
std::ostream& operator << (std::ostream& out, const array_list<__IO__>& l) {
        l.output(out);
        return out;
}

#endif

