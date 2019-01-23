#include <algorithm>
#include <iostream>
#include <iterator>

//< 27
template <class T, class InputIterator>
T accumulate ( InputIterator begin, InputIterator end, T initial_value){
        T sum = initial_value;
        for (InputIterator it = begin; it != end; it ++) {
                sum += *it;
        }

        return sum;
}

//< 28
template < class T, class InputIterator, class Operator >
T accumulate ( InputIterator begin, InputIterator end, T initial_value,
                Operator operation){
        auto sum = *begin;
        for ( InputIterator it = begin+1; it != end; it ++ ) {
                sum = operation(sum, *it);
        }
        sum += initial_value;
        return sum;
}

//< 29
template < class T >
void copy( T start, T end, T to ) {
        T dest = to;
        for ( T it = start; it != end; it++, dest++ ) {
                *dest = *it;
        }
}

//< 30
template<class T>
void permutations(T list[], int k, int m){
        std::sort(list, list+m+1);
        do {
                std::copy(list, list+m+1,
                                std::ostream_iterator<T>(std::cout, ""));
                std::cout << std::endl;
        } while (std::next_permutation(list, list+m+1));
}

//< 31
template<class T>
void permutations2(T list[], int k, int m){
        auto temp = new T[m];
        std::copy(list, list+m+1, temp);
        do {
                std::copy(list, list+m+1,
                                std::ostream_iterator<T>(std::cout, ""));
                std::cout << std::endl;
        } while (std::next_permutation(list, list+m+1));
        while ( std::prev_permutation( temp, temp+m+1 )) {
                std::copy(temp, temp+m+1,
                                std::ostream_iterator<T>(std::cout, ""));
                std::cout << std::endl;
        }
        delete [] temp;
}

//< 32
template<class T>
void permutations3(T list[], int k, int m){
        while ( std::next_permutation(list, list+m+1) ) {}
        do {
                std::copy(list, list+m+1,
                                std::ostream_iterator<T>(std::cout, ""));
                std::cout << std::endl;
        } while ( std::next_permutation(list, list+m+1) );
}


int main (int argc, char * argv[]) {
        int test[] = {0, 1, 2, 3};
        std::cout << accumulate(test, test+4, 0) << std::endl;
        std::cout << accumulate(test+2, test+4, 0, std::multiplies<int>())
                << std::endl;
        int dest[4] = {};
        copy( test, test+4, dest );
        std::cout << dest[2] << std::endl;

        /*
        dest[0] = 3;
        dest[1] = 2;
        dest[2] = 1;
        dest[3] = 0;
        permutations(dest, 0, 3);
        */

        dest[0] = 2;
        dest[1] = 3;
        dest[2] = 0;
        dest[3] = 1;
        permutations3(dest, 0, 3);
        return 0;
}

