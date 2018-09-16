#include <iostream>
#include <vector>

//< 10
int abc(int a, int b, int c){
	if(a<0 && b<0 && c<0){
		throw 1;
	}else if(a==0 && b==0 && c==0){
		throw 2;
	}

	return a+b+c;
}

//< 11
template <typename __cmp__>
int count(const std::vector<__cmp__> & a, __cmp__ value) {
	int count = 0;

	if(a.size() < 1){
		throw "Empty vector!";
	}

	for(auto v : a){
		if(v == value){
			count++;
		}
	}

	return count;
}

int main(int argc, char * argv[]){
	std::vector<int> a;

	try{
		abc(0, 0, 0);
	}catch(int e){
		std::cout << "Exception number is " << e << "!" << std::endl;
	}

	try {
		count(a, 3);
	} catch (const char* e) {
		std::cout << "Exception info is " << e << "!" << std::endl;
	}

	return 0;
}

