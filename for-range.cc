#include <iostream>

int main(int argc, char * argv[]){

	int array[] {-1,2,4,99};

	for(auto i : array){
		std::cout << i << std::endl;
	}

	return 0;
}

