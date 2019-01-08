/*! \brief the algorithm to solve offline equivalence set problem
 *  \author Shylock Hg
 *  \date 2019-01-05
 *  \email tcath2s@gmail.com
 * */



#include "offline_equivalence_set.hh"

int main(int argc, char * argv[]) {
        // relationships
        std::array<std::pair<int, int>, 11> ships {
                std::make_pair(1, 5),
                std::make_pair(1, 6),
                std::make_pair(3, 7),
                std::make_pair(4, 8),
                std::make_pair(5, 2),
                std::make_pair(6, 5),
                std::make_pair(4, 9),
                std::make_pair(7, 8),
                std::make_pair(9, 7),
                std::make_pair(3, 4),
                std::make_pair(6, 2),
        };
        relationships<11> r(std::move(ships));
        auto sets = r.get_equivalence_set();

        // show the results
        for (const auto & s : sets) {
                for (const auto & ele : s) {
                        std::cout << ele << " ";
                }
                std::cout << std::endl;
        }
        return 0;
}

