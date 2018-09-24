#include "Vector.h"

#include <iostream>

int main(int argc, char * argv[]){

	Vector v{2.8, 3.3, 4.0};

	for(auto &x : v){  //!< require `begin()` and `end()`
		std::cout << x << std::endl;
	}

	std::cout << "The v[2] is " << v[2] << std::endl;

	return 0;
}

