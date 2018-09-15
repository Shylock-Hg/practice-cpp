#include <iostream>

int main(int argc, char * argv[]){

	int array[] {-1,2,4,99};
	for(auto i : array){
		std::cout << i << std::endl;
	}

	char * string = "hello";
	for(auto c : string){
		
	}

	return 0;
}

