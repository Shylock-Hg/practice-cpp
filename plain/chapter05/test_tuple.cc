#include <iostream>
#include <tuple>

int main(int argc, char * argv[]){
	auto t = std::make_tuple("string", 2, true);
	std::cout << std::get<0>(t) << std::get<1>(t) << std::get<2>(t) /*<< std::get<3>(t)*/ << std::endl;
	return 0;
}


