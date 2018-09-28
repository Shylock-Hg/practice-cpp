#include <iostream>
#include <random>
#include <functional>

int main(int argc, char * argv[]){
	auto die = std::bind(std::uniform_int_distribution<> {1,7}, std::default_random_engine {});
	std::cout << die() << die() << die() << die() << std::endl;
	return 0;
}

