#include <iostream>
#include <string>
#include <type_traits>
#include <map>
#include <iterator>

///////////////////////////////////////////////////////////////////////////////

//< using function overload

template <class T>
T adder(T b) {  //!< terminal of recursive procedure
        return b;  //!< return the final value
}

template <class T, class... Args>
T adder(T first, Args... args) {  //!< middle of recursive procedure
        return first + adder(args...);  //!< unpack the variadic parameter
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
template <class __comp__>
bool pair_comp(__comp__ a, __comp__ b) {
        return a == b;
}

template <class __comp__, class... Args>
bool pair_comp(__comp__ a, __comp__ b, Args... args) {
        return (a == b) && pair_comp(args...);
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
template <class... Ts>
struct tuple {};

template <class T, class... Ts>
struct tuple<T, Ts...> : tuple<Ts...> {
        tuple(T first, Ts... ends) : tuple<Ts...>(ends...), tail(first){}
        T tail;
};

template <std::size_t, class>
struct elem_type_holder;

template <class T, class... Ts>
struct elem_type_holder<0, tuple<T, Ts...>> {
        typedef T value_t;
};

template <std::size_t k, class T, class... Ts>
struct elem_type_holder<k, tuple<T, Ts...>> {
        typedef typename elem_type_holder<k-1, tuple<Ts...>>::value_t value_t;
};

template <std::size_t k, class... Ts>
typename std::enable_if
<0 == k, typename elem_type_holder<0, tuple<Ts...>>::value_t&>::type
get(tuple<Ts...>& t) {
        return t.tail;
}

template <std::size_t k, class T, class... Ts>
typename std::enable_if
<0 != k, typename elem_type_holder<k, tuple<T, Ts...>>::value_t&>::type
get(tuple<T, Ts...>& t) {
        tuple<Ts...>& base = t;
        return get<k-1>(base);
}
///////////////////////////////////////////////////////////////////////////////


int main(int argc, char * argv[]) {
        std::cout << adder(0, 1, 2, 3) << std::endl;
        std::cout
                << adder(std::string("hello "), std::string("world"))
                << std::endl;

        std::cout << pair_comp(1, 1, 2, 2, 3, 3) << std::endl;
        std::cout << pair_comp(1, 1, 2, 3, 3, 3) << std::endl;
//        std::cout << pair_comp(1, 1, 2, 2, 3) << std::endl;

        tuple<const char *, int, float> t = {"hello", 1, 1.1};
        std::cout << t.tail << std::endl;
        // std::cout << get<-1>(t) << std::endl;
        std::cout << get<0>(t) << std::endl;
        std::cout << get<1>(t) << std::endl;
        std::cout << get<2>(t) << std::endl;
        // std::cout << get<3>(t) << std::endl;

        //std::map<std::string, int> m {{"key0", 0}, {"key1", 1}, {"key2", 2}};
        return 0;
}

