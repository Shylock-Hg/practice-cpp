#include <exception>
#include <iostream>


class array_out_of_range : public std::out_of_range{
	public:
	explicit array_out_of_range(const char * desc) : out_of_range(desc){};
};


int main(int argc, char * argv[]){

	int i = -1;

	try{
		if(i < 0){
			throw array_out_of_range(static_cast<const char*>("Array out of range!"));
		}
		
	}catch(std::out_of_range& e){
		std::cout << e.what() << std::endl;
	};

	
	return 0;
}

