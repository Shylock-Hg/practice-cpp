/*! \brief 
 *  \author Shylock Hg
 *  \date 2019-01-08
 *  \email tcath2s@gmail.com
 * */

#ifndef _MAZE_HH_
#define _MAZE_HH_

#include "../chapter07-matrix/matrix_array.hh"

#include <utility>
#include <vector>

/*! \brief the algorithm to get the path of maze
    \note true for pass, false for block
*/
template <std::size_t ROW, std::size_t COL>
class maze : matrix_array<bool, ROW, COL> {
public:
        /*! \brief find the path from start to end
            \param start start position
            \param end end position
            \retval the path sequence, empty for no way
        */
        std::vector<std::pair<std::size_t, std::size_t>> path(
                std::pair<std::size_t, std::size_t> start,
                std::pair<std::size_t, std::size_t> end) const {
                std::vector<std::pair<std::size_t, std::size_t>> path;
                //!< \TODO to find the path
                return path;  //!< automatic move
        }
};

#endif  //!< _MAZE_HH_

