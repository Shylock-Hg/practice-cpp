#include <iostream>

class A {
	public:
		A(){
			std::cout << "A" << std::endl;
		}
		~A(){
			std::cout << "~A" << std::endl;
		}

		void fa(){
			std::cout << "fA" << std::endl;
		}

};

class B : public A{
	public:
		B() : A(){
			std::cout << "B" << std::endl;
		};

		/*  //!< only for constructor
		void fb() : fa(){
			std::cout << "fB" << std::endl;
		}
		*/
};

class C : public B{
	public:
		C() : B(){
			std::cout << "C" << std::endl;
		}

		/*
		void fc() : fb(){
			std::cout << "fC" << std::endl;
		}
		*/
};

int main(int argc, char * argv[]){
	C c;

	return 0;
}

