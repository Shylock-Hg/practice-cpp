#include <iostream>
#include <type_traits>

template <size_t arg, size_t... rest>
struct IntegerMax;

template <size_t arg>
struct IntegerMax<arg> : std::integral_constant<size_t, arg>
{
};

template <size_t arg1, size_t arg2, size_t... rest>
struct IntegerMax<arg1, arg2, rest...> : std::integral_constant<size_t, arg1 >= arg2 ? IntegerMax<arg1, rest...>::value :
    IntegerMax<arg2, rest...>::value >
{
};

int main(int argc, char * argv[]){
	std::cout << std::is_arithmetic<int>() << std::endl;
	std::cout << std::is_void<int>() << std::endl;

	std::cout << "Max is " << IntegerMax<1, 2, 4, 2, 3, 1, 0>::value << std::endl;

	return 0;
}


