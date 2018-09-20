#include <iostream>

bool accept(){
	std::cout << "Please input y/n:" << std::endl;
	char answer;
	std::cin >> answer;

	return 'y' == answer;
}

bool accept1(int count){
	while(static_cast<bool>(count--)){
		std::cout << "Please input y/n:" << std::endl;
		char answer;
		std::cin >> answer;
		if('y' == answer){
			return true;
		}
		if('n' == answer){
			return false;
		}
		std::cerr << "Error : please input `y` or `n`!" << std::endl;
	}

	return false;
}

int main(int argc, char * argv[]){

	if(accept1(4)){
		std::cout << "Accepted" << std::endl;
	}else{
		std::cout << "Don't accepted" << std::endl;
	}

	return 0;
}

