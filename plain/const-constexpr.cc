#include <iostream>

//!< just can reference const modified external variable
static const int g = 1;

constexpr double square(const double a){
	int v = 1;
	//static const int s = 1;  //!< can't reference static variable
	return a*a*v*g/**s*/;
}

int main(int argc, char * argv[]){
    constexpr double dmv = 1.3;
    double var = 1.4;

    constexpr double e0 = 2.3 * square(dmv);
    //constexpr double e1 = 2.3 * square(var);  //!< error 
    //
    std::cout << "Constexpr e0 is " << e0 << '.' << std::endl;

    return 0;
}

