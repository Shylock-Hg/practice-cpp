/*! \brief 
 *  \author Shylock Hg
 *  \date 2019-01-08
 *  \email tcath2s@gmail.com
 * */

#include "maze.hh"

int main(int argc, char * argv[]) {
        maze<10, 10> m {
                {true,  false, false, false, false, false, true,  true,  true,  true},
                {true,  true,  true,  true,  true,  false, true,  false, true,  true},
                {true,  true,  true,  false, true,  false, true,  true,  true,  true},
                {true,  false, true,  false, true,  false, true,  false, false, true},
                {true,  false, true,  false, true,  false, true,  false, true,  true},
                {true,  false, false, false, true,  false, true,  false, true,  false},
                {true,  false, true,  true,  true,  false, true,  false, true,  false},
                {true,  false, true,  false, false, false, true,  false, true,  true},
                {false, true,  true,  true,  true,  true,  true,  false, true,  true},
                {true,  true,  true,  true,  false, false, false, false, true,  true}
        };
        if (m.find_path(
                std::pair<std::size_t, std::size_t> {0, 0},
                std::pair<std::size_t, std::size_t> {9, 9}
        )) {
                while (!m.get_path().empty()) {
                        std::pair<std::size_t, std::size_t> p = m.get_path().pop();
                        std::clog << '(' << p.first << ',' << p.second << ')' << std::endl;
                }
        } else {
                std::clog << "No Way!" << std::endl;
        }
        return 0;
}
