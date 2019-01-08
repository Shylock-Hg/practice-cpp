#include <iostream>
#include <vector>

//< 2
template<typename __cmp__>
int count(const std::vector<__cmp__> & a, __cmp__ value) {
	int count = 0;

	for(auto v : a){
		if(v == value){
			count++;
		}
	}

	return count;
}

//< 3
template<typename __assign__>
void fill(std::vector<__assign__> & a, __assign__ value){
	for(auto & it : a){
		it = value;
	}
}

//< 4
template<typename __arithmetic__>
__arithmetic__ inner_product(std::vector<__arithmetic__> & a, std::vector<__arithmetic__> & b){
	__arithmetic__ sum = 0;

	int size = a.size() < b.size() ? a.size() : b.size();

	for(int i=0; i<size; i++){
		sum += (a[i] * b[i]);
	}

	return sum;
}

//< 5
template<typename __arithmetic__>
void iota(std::vector<__arithmetic__> & a, __arithmetic__ value){
	__arithmetic__ i = 0;

	for(auto & it : a){
		it += (value + i++);
	}
}

//< 6
template<typename __cmp__>
bool is_sorted(std::vector<__cmp__> & a){
	int i = 0;
	int count = a.size();

	for(i=0; i<count-1; i++){
		if(a[i] < a[i+1]){
			break;
		}
	}
	if(i == count-1){
		return true;
	}

	for(i=0; i<count-1; i++){
		if(a[i] > a[i+1]){
			break;
		}
	}
	if(i == count-1){
		return true;
	}

	return false;
}

//< 7
template<typename __cmp__>
int mismatch(std::vector<__cmp__> & a, std::vector<__cmp__> &b){
	int i = 0;
	int min = a.size() < b.size() ? a.size() : b.size();

	for(i=0; i<min; i++){
		if(a[i] != b[i]){
			return i;
		}
	}

	return -1;
}

//< 9
int abc(int a, int b, int c){
	return a+b+c;
}
int abc(float a, float b, float c){
	return a+b+c;
}

int main(int argc, char * argv[]) {

	std::vector<int> a {-1, 2, 3, 0, 2, 1, 235, 23, 2, 23, 521, 52, 3};
	std::cout << "Count of 3 is " << count(a, 3) << std::endl;

	fill(a, 3);
	std::cout << "Vector[0] is " << a[0] << std::endl;

	std::vector<int> b {2, 3, 0, 1, 4};
	std::cout << "Inner product is " << inner_product(a, b) << std::endl;

	iota(b, 3);
	std::cout << "Iota is " << b[0] << std::endl;

	std::vector<int> c {1, 2, 3, 4, 5};
	std::cout << "Is sorted ? " << is_sorted(c) << std::endl;

	std::vector<int> d {1, 2, 2};
	std::cout << "Mismatch is " << mismatch(c, d) << std::endl;

	std::cout << abc(1, 2, 3) << std::endl;
	std::cout << abc(1.0F, 2.0F, 3.0F) << std::endl;
	//std::cout << abc(1, 2, 3.0F) << std::endl;  //!< (int, int, float)
	//std::cout << abc(1.0, 2.0, 3.0) << std::endl;  //!< (double, double, double)

	return 0;
}

