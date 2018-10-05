#include <stdexcept>
#include <iterator>

#include "linear_list.hh"

template <class __item__>
struct link_list_node {
private:
        __item__ value;
        link_list_node * next;
public:
        //< init
        link_list_node() = default;
        link_list_node(const __item__& _value,
                        /*const*/ link_list_node<__item__>* _next) :
                value {_value}, next {_next} {}
        //< copy
        link_list_node(const link_list_node<__item__>& node) :
                next {node.next} , value {node.value} {}
        //< copy from value
        explicit link_list_node(const __item__& _value) :
                value {_value}, next {nullptr} {}

        __item__& get_value() {return value;}
        const __item__& get_value() const {return value;}

        link_list_node<__item__>* get_next() {return next;}
        const link_list_node<__item__>* get_next() const {return next;}

        void set_next(link_list_node<__item__>* _next) {next = _next;}
};

template <class __item__>
class link_list : public linear_list<__item__> {
private:
        link_list_node<__item__> * first;
        size_t count;

public:
        class iterator :
        public std::iterator<
        std::forward_iterator_tag,
        link_list_node<__item__>> {
        public:
                typedef link_list_node<__item__>* pointer;
                typedef link_list_node<__item__>& reference;
        protected:
                pointer p;

        public:
                //< constructor 
                iterator() = default;
                explicit iterator(pointer init) : p {init} {}

                //< dereference operator
                reference operator*() const {return *p;}
                pointer operator->() const {return p;}

                //< succ
                iterator& operator++() {
                        if(nullptr == p){
                                throw std::out_of_range(
                                                "Link list out of range`prefix++`!");
                        }
                        return p = p->get_next(), *this;
                }
                iterator operator++(int) {
                        if(nullptr == p){
                                throw std::out_of_range(
                                                "Link list out of range`postfix--`!");
                        }
                        iterator temp = *this;
                        p = p->next;
                        return temp;
                }

                //< dec
                /*
                   iterator& operator--() {
                   }
                   iterator operator--(int) {
                   }
                   */

                //< equl
                bool operator!=(const iterator right) const {
                        return p != right.p;
                }
                bool operator==(const iterator right) const {
                        return p == right.p;
                }

        };

        link_list() : linear_list<__item__>(), count {0}, first {nullptr} {}
        //< copy
        link_list(const link_list<__item__>& list) : count {list.count} {
                link_list_node<__item__>* it = first =
                        new link_list_node<__item__>(list.first->value);
                for (const auto & i : list) {
                        if(i.p == list.first){
                                link_list_node<__item__>* it = first =
                                        new link_list_node<__item__>(
                                                        i.first->value);
                        }else{
                                it->next = new link_list_node<__item__>(
                                                i.p->value);
                                it = it->next;
                        }
                }
        }
        //< move
        link_list(link_list<__item__>&& list) noexcept :
                count {list.count}, first {list.first} {
                list.count = 0;
                list.first = nullptr;
        }

        ~link_list() {
                for (auto& i : *this) {
                        delete &i;
                }
        }

        iterator begin() {
                iterator item(first);
                return item;
        }
        const iterator begin() const {
                iterator item(first);
                return item;
        
        }
        iterator end() {
                iterator item(nullptr);
                return item;
        }
        const iterator end() const {
                iterator item(nullptr);
                return item;
        }

        bool empty() const {
                return static_cast<bool> (!count);
        }

        size_t size() const {
                return count;
        }

        __item__& at(size_t i) const {
                if(i >= count){
                        throw std::out_of_range(
                                        "Link list out of range `at`!");
                }
                for (auto & it : *this) {
                        if (0 == (i--)) {
                                return (it.get_value());
                        }
                }
                throw std::out_of_range(
                                "Link list out of range `at`!");
        }

        int find(const __item__& value) const {
                int i = 0;
                for (const auto & it : *this) {
                        i++;
                        if (value == it.get_value()) {
                                return i;
                        }
                }
                return -1;
        }

        void erase(size_t i) {
                if (i >= count) {
                        throw std::out_of_range(
                                        "Link list out of range `erase`!");
                }
                if (0 == i) {
                        auto drop = first;
                        first = first->get_next();
                        delete drop;
                        count--;
                        return;
                }
                for (auto & it : *this) {
                        if (1 == i) {
                                auto drop = it.get_next();
                                it.set_next(it.get_next()->get_next());
                                delete drop;
                        }
                        /*
                        if (0 == i) {
                                delete &it;
                        }
                        */
                        i--;
                }
                count--;
        }
        void insert(size_t i, const __item__& value) {
                if (i > count) {
                        throw std::out_of_range(
                                        "Link list out of range `insert`!");
                }
                if (0 == i) {
                        first = new link_list_node<__item__>(
                                        value,
                                        first ? first : nullptr);
                        count++;
                        return;
                }
                for (auto & it : *this) {
                        if (1 == i--) {
                                it.set_next(new link_list_node<__item__>(
                                                value, it.get_next()));
                                count++;
                        }
                }
        }
        void output(std::ostream& out) const {
                for (const auto & it : *this) {
                        std::ostream_iterator<__item__> (out, " ") = it.get_value();
                }
        }
};


