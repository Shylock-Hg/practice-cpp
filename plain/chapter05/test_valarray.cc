#include <valarray>
#include <iostream>

int main(int argc, char * argv[]){
	std::valarray<int> a1 = {1, 2, 3};
	std::valarray<int> a2 = {1, 2, 3};
	std::valarray<int> a3 = a1-a2;
	//std::valarray<float> a4 = a1*a2; 
	std::cout << a3[0] << ',' << a3[1] << ',' << a3[2] << std::endl;
	return 0;
}

