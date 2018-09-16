#include <iostream>

template <typename it>
void new2dArray(it ** & x, unsigned int rows, unsigned int columns){
        x = new it * [rows];

        /*  //!< error for iterating
            for(auto & column : x){
            std::cout << "New columns" << std::endl;
            column = new it[columns];
            }
            */
        for(unsigned int i=0; i<rows; i++){
                x[i] = new it[rows];
        }
}

template <typename it>
void release2dArray(it ** & x, unsigned int rows){
        /*  //!< error for iterating
            for(auto & column : x){
            std::cout << "Delete columns" << std::endl;
            delete [] column;
            }
            */
        for(unsigned int i=0; i<rows; i++){
                delete [] x[i];
        }

        delete [] x;
        x = nullptr;
}

//< 12
template <typename it>
void new2dArray$(it ** & x, unsigned int rows, const unsigned int * y){
        x = new it * [rows];
        for(unsigned int i=0; i<rows; i++){
                x[i] = new it[y[i]];
        }
}

//< 13
template <typename it>
void changeLength1D(it * & x, unsigned int oldLength, unsigned int newLength){
        it * y = new it[newLength];
        for(int i=0; i<(oldLength < newLength ? oldLength : newLength); i++){
                y[i] = x[i];
        }
        delete [] x;
        x = y;
}

//< 14
template <typename it>
void changeLength2D(it ** & x, unsigned int oldRows, unsigned int oldColumns, 
                unsigned int newRows, unsigned int newColumns){
        it ** y;
        new2dArray(y, newRows, newColumns);

        for(int r=0; r<(oldRows < newRows ? oldRows : newRows); r++){
                for(int c=0; c<(oldColumns < newColumns ? oldColumns : newColumns); c++){
                        y[r][c] = x[r][c];
                }
        }
}

int main(int argc, char * argv[]){
        int ** twod;
        new2dArray(twod, 3U, 3U);
        release2dArray(twod, 3U);

        int ** twod$;
        const unsigned int row[3] {1, 2, 3};
        new2dArray$(twod$, 3U, static_cast<const unsigned int *> (row));
        release2dArray(twod$, 3U);

        int * a = new int[3] {1, 2, 3};
        changeLength1D(a, 3, 5);
        for(int i=0; i<5; i++){
                std::cout << a[i] << std::endl;
        }
        delete [] a;

        char ** twod$$;
        new2dArray(twod$$, 4U, 4U);
        changeLength2D(twod$$, 4U, 4U, 3U, 3U);
        for(int r=0; r<3; r++){
                for(int c=0; c<3; c++){
                        twod$$[r][c] = 'c';
                        std::cout << twod$$[r][c] << std::endl;
                }
        }
        release2dArray(twod$$, 3U);

        return 0;
}

