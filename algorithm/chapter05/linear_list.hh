#include <cstddef>
#include <iostream>

#ifndef _LINEAR_LIST_H_
#define _LINEAR_LIST_H_

template <class __item__>
class linear_list {
public:
        virtual ~linear_list(){}
        virtual bool empty() const = 0;
        virtual size_t size() const = 0;
        virtual __item__& at(size_t i) const = 0;
        virtual int find(const __item__& value) const =0;
        virtual void erase(size_t i) = 0;
        virtual void insert(size_t i, const __item__& value) = 0;
        virtual void push_back(const __item__& value) = 0;
        virtual void output(std::ostream& out) const = 0;
};

#endif

