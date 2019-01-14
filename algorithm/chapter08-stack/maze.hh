/*! \brief 
 *  \author Shylock Hg
 *  \date 2019-01-08
 *  \email tcath2s@gmail.com
 * */

#ifndef _MAZE_HH_
#define _MAZE_HH_

#include "../chapter07-matrix/matrix_array.hh"
#include "./list_stack.hh"

#include <stdexcept>
#include <utility>
#include <vector>


/*! \brief the algorithm to get the path of maze
    \note true for pass, false for block
*/
template <std::size_t ROW, std::size_t COL>
class maze : matrix_array<bool, ROW, COL> {
private:
        static std::size_t pos_2_index(std::pair<std::size_t, std::size_t> p) {
                // (x, y) -> index
                return p.first + p.second*COL;
        }
public:
        /*! \brief find the path from start to end
            \param path the path of maze
            \param start start position
            \param end end position
            \retval the path sequence, empty for no way
        */
        bool find_path(
                list_stack<std::pair<std::size_t, std::size_t>> path,
                std::pair<std::size_t, std::size_t> start,
                std::pair<std::size_t, std::size_t> end
        ) const {
                // check arguments
                if (!path.is_empty()) {
                        throw std::invalid_argument("Not empty input path stack!");
                }
                // check point in maze
                if (start.first >= COL || start.second >= RAW) {
                        throw std::invalid_argument("Outside start point!");
                }
                if (ele[pos_2_index(start)] != true) {
                        throw std::invalid_argument("Blocked start!");
                }
                if (end.first >= COL || end.second >= RAW) {
                        throw std::invalid_argument("Outside end point!");
                }
                if (ele[pos_2_index(end)] != true) {
                        throw std::invalid_argument("Blocked end!");
                }
                //!< \TODO to find the path
                std::pair<std::size_t, std::size_t> current = start;
                while(current != end) {  //!< not find the path
                        //!< current can't pass                                
                        if (!ele[pos_2_index(current)]) {
                                
                        }
                }
                return true;
        }
};

#endif  //!< _MAZE_HH_
