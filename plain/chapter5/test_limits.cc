#include <iostream>
#include <limits>

int main(int argc, char * argv[]){
	static_assert(std::numeric_limits<char>::is_signed, "Unsigned char!");
	std::cout << std::numeric_limits<char>::is_signed << std::endl;
	return 0;
}

