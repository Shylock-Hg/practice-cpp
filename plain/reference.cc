#include <iostream>

int main(int argc, char * argv[]){

	int array[] {1,2,3,4};

	for(auto & it : array){
		std::cout << it << std::endl;
	}

	return 0;
}

