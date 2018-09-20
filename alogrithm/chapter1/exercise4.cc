#include <cmath>
#include <exception>
#include <iostream>

//< 19
int factorial(int n){
        if(n < 0){
                throw std::invalid_argument("Invalid factorial number!");
        }
        int sum = 1;
        for(int i=0; i<n; i++){
                sum *= (n-i);
        }

        return sum;
}

//< 20
int fabonacci(int n){
        if(0 > n){
                throw std::invalid_argument("Invalid fabonacci number!");
        }
        if(0 == n){
                return 0;
        }
        if(1 == n){
                return 1;
        }

        return fabonacci(n-1)+fabonacci(n-2);
}

int fabonacci_iter(int n){
        if(0 > n){
                throw std::invalid_argument("Invalid fabonacci number!");
        }
        int a = 0;
        int b = 1;
        int c = 0;
        if(1 == n){
                return a;
        }
        if(2 == n){
                return b;
        }
        for(int i=0; i<n-2; i++){
                c = a;
                a = b;
                b = b+c;
        }

        return b;
}

//< 21
int fn(int n){
        if(0 > n){
                throw std::invalid_argument("Invalid negative number!");
        }
        if(n % 2 == 0){
                return n/2;
        }

        return fn(3*n+1);
}
int fn_iter(int n){
        if(0 > n){
                throw std::invalid_argument("Invalid negative number!");
        }
        
        return (3*n+1)/2;
}

//< 22
int acker(int i, int j){
        if(1 > i || 1 > j){
                throw std::invalid_argument("Invalid number of acker!");
        }

        if(i==1 && j>=1){
                int ret = 1;
                for(int i=0; i<j; i++){
                        ret *= 2;
                }
                return ret;
        }
        if(i>=2 && j==1){
                return acker(i-1, 2);
        }
        if(i>=2 && j>=2){
                return acker(i-1, acker(i, j-1));
        }

        return -1;
}

//< 23
int gcd(int x, int y){
        if(0 > x || 0 > y){
                throw std::invalid_argument("Invalid number of gcd!");
        }

        if(0 == y){
                return x;
        }

        return gcd(y, x % y);
}

//< 24
template <class __it__>
bool in(const __it__* a, unsigned int count, __it__ it, unsigned int i){
        if(a[i] == it){
                return true;
        }
        if(i == count - 1){
                return false;
        }

        return in(a, count, it, i+1);
}

int main(int argc, char * argv[]){

        std::cout << "The factorial of " << 4 << " is " << factorial(4) << std::endl;

        std::cout << "The fabonacci of " << 4 << " is " << fabonacci_iter(4) << std::endl;

        std::cout << "Fn(" << 5 << ") is " << fn_iter(5) << std::endl;

        std::cout << "Acker of " << 2 << ' ' << 2 << " is " << acker(2, 2) << std::endl;

        std::cout << "Gcd of " << 112 << ' ' << 42 << " is " << gcd(112, 42) << std::endl;

        int a[] = {2, 3, 4, 5, 1, 5, 67};
        std::cout << "Is " << 77 << " in array : " <<
                in(static_cast<int*>(a), 7U, 77, 0U) << std::endl;
        
        return 0;
}

