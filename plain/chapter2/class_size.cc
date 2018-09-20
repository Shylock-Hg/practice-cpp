#include <cstdint>
#include <iostream>

class test {
private:
	//uintptr_t i;
	int i;
public:
	test(){};  //!< don't storage in object
	void inc(){i++;};  //!< don't storage in object
	virtual void dec(){i--;};  //!< pointer of virtual function table
	virtual void dummy() = 0;  //!< constraint in compile time

	enum e {t0, t1, t2};  //!< constraint in compile time
};

//!< (compile time)the ordinary member method just function with default first parameter assigned by this pointer
//!< (run time)the virtual functions storage the pointer to virtual function table in the object
//!< (compile time)the pure viertual functions 

int main(int argc, char * argv[]){

	//test t;

	std::cout << sizeof(test) << std::endl;

	std::cout << test::t2 << std::endl;

	std::cout << test::t1 << std::endl;
	test::e et = test::t0;
	std::cout << (et<test::t1) << std::endl;
	
	return 0;
}

