/*! \brief algorithm to solve problem -- tower of hanoi
 *  \author Shylock Hg
 *  \date 2018-12-30
 *  \email tcath2s@gmail.com
 * */

#include <type_traits>
#include <iostream>

#include "list_stack.hh"

void hanoi(const std::size_t count);

int main(int argc, char * argv[]) {
        hanoi(8);
        return 0;
}


static constexpr std::size_t TOWER_COUNT = 3;

void hanoi_move(
        list_stack<int> towers[TOWER_COUNT],
        std::size_t n,
        std::size_t s1,
        std::size_t s2,
        std::size_t s3);


/*! \brief complete problem -- tower of hanoi
    \param count: the count of plates
*/
void hanoi(const std::size_t count) {
        //!< initialize
        list_stack<int> towers[TOWER_COUNT];

        for (int i = count - 1; i >= 0; i--) {
                towers[0].push(i);
        }

        hanoi_move(towers, count, 0, 1, 2);

        for (int _ = 0; _ < count; _++) {
                std::cout << towers[1].pop() << std::endl;
        }
}

/*! \brief move n count plates from s0 to s1
    \note: time O(2^N)
*/
void hanoi_move(
        list_stack<int> towers[TOWER_COUNT],
        std::size_t n,
        std::size_t s0,
        std::size_t s1,
        std::size_t s2) {
        if (n == 0) {  // move ok
                return;
        }

        // move n -1 count plates from s0 to s1
        hanoi_move(towers, n - 1, s0, s2, s1);
        towers[s1].push(towers[s0].pop());
        // move n -1 count plates from s2 to s0
        hanoi_move(towers, n - 1, s2, s1, s0);
}
