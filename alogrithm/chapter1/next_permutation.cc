#include <iostream>
#include <iterator>
#include <algorithm>

template<class T>
void permutations(T list[], int k, int m){
        do {
                std::copy(list, list+m+1,
                                std::ostream_iterator<T>(std::cout, ""));
                std::cout << std::endl;
        } while (std::next_permutation(list, list+m+1));
}

int main(int argc, char * argv[]){
        int l[] = {0, 1, 2, 3};

        permutations(l, 0, 3);

        return 0;
}

