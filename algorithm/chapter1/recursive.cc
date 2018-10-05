#include <iostream>

int factorial(int n){
        if(n <= 0){
                return 1;
        }
        return n*factorial(n-1);
}

template <class __arithmetic__>
__arithmetic__ rSum(__arithmetic__ x[], int n){
        if(n <= 0){
                return 0;
        }

        return rSum(x, n-1)+x[n-1];
}

template<class __it__>
void swap(__it__ & a, __it__ & b){
        __it__ c;
        c = b;
        b = a;
        a = c;
}

template <class __it__>
void permulations(__it__ list[], int k, int m){
        if(k == m){
                for(int i=0; i<=m; i++){
                        std::cout << list[i] << ',';
                }
                std::cout << std::endl;
        }else{
                for(int i=k; i<=m; i++){
                        swap(list[k], list[i]);
                        permulations(list, k+1, m);
                        swap(list[k], list[i]);
                }
        }
}

int main(int argc, char * argv[]){

        std::cout << "Factorial(3) is " << factorial(3) << std::endl;

        int a[] = {3,2,1};
        std::cout << "Sum of array is " << rSum(a, 3) << std::endl;

        permulations(a, 0, 2);

        return 0;
}

