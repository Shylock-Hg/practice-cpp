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
class maze : public matrix_array<bool, ROW, COL> {
private:
        std::pair<std::size_t, std::size_t> current;
        list_stack<std::pair<std::size_t, std::size_t>> path;
private:
        static std::size_t pos_2_index(std::pair<std::size_t, std::size_t> p) {
                // (x, y) -> index
                return p.first + p.second*COL;
        }

        bool try_move_left() {
                if (current.first == 0) {
                        return false;  //!< can't pass for boundary
                }
                if (! matrix_array<bool, ROW, COL>::ele[pos_2_index(
                        std::pair<std::size_t, std::size_t> {
                                current.first - 1, current.second
                        }
                )]) {
                        return false;  //!< can't pass for blocking
                }

                // push now
                path.push(current);
                matrix_array<bool, ROW, COL>::ele[pos_2_index(current)] = false;
                // go left
                current.first -= 1;
                return true;
        }

        bool try_move_right() {
                if (current.first >= (COL - 1)) {
                        return false;  //!< can't pass for boundary
                }
                if (! matrix_array<bool, ROW, COL>::ele[pos_2_index(
                        std::pair<std::size_t, std::size_t> {
                                current.first + 1, current.second
                        }
                )]) {
                        return false;  //!< can't pass for blocking
                }

                // push now
                path.push(current);
                matrix_array<bool, ROW, COL>::ele[pos_2_index(current)] = false;
                // go right
                current.first += 1;
                return true;
        }

        bool try_move_up() {
                if (current.second == 0) {
                        return false;  //!< can't pass for boundary
                }
                if (! matrix_array<bool, ROW, COL>::ele[pos_2_index(
                        std::pair<std::size_t, std::size_t> {
                                current.first, current.second - 1
                        }
                )]) {
                        return false;  //!< can't pass for blocking
                }

                // push now
                path.push(current);
                matrix_array<bool, ROW, COL>::ele[pos_2_index(current)] = false;
                // go right
                current.second -= 1;
                return true;
        }

        bool try_move_down() {
                if (current.second >= (ROW -1)) {
                        return false;  //!< can't pass for boundary
                }
                if (! matrix_array<bool, ROW, COL>::ele[pos_2_index(
                        std::pair<std::size_t, std::size_t> {
                                current.first, current.second + 1
                        }
                )]) {
                        return false;  //!< can't pass for blocking
                }

                // push now
                path.push(current);
                matrix_array<bool, ROW, COL>::ele[pos_2_index(current)] = false;
                // go right
                current.second += 1;
                return true;
        }
public:
        maze(const std::initializer_list<std::initializer_list<bool>> &list) : 
                matrix_array<bool, ROW, COL>(list)
                // path : {},
                // current : {}
                {
        }

        /*! \brief find the path from start to end
            \param path the path of maze
            \param start start position
            \param end end position
            \retval the path sequence, empty for no way
        */
        bool find_path(
//                list_stack<std::pair<std::size_t, std::size_t>> path,
                std::pair<std::size_t, std::size_t> start,
                std::pair<std::size_t, std::size_t> end
        ) const {
                // check arguments
                if (!path.empty()) {
                        throw std::invalid_argument("Not empty input path stack!");
                }
                // check point in maze
                if (start.first >= COL || start.second >= ROW) {
                        throw std::invalid_argument("Outside start point!");
                }
                if (matrix_array<bool, ROW, COL>::ele[pos_2_index(start)] != true) {
                        throw std::invalid_argument("Blocked start!");
                }
                if (end.first >= COL || end.second >= ROW) {
                        throw std::invalid_argument("Outside end point!");
                }
                if (matrix_array<bool, ROW, COL>::ele[pos_2_index(end)] != true) {
                        throw std::invalid_argument("Blocked end!");
                }
                //!< \TODO to find the path
                current = start;
                while(current != end) {  //!< not in the end
                        // current can't pass                                
                        if (!matrix_array<bool, ROW, COL>::ele[pos_2_index(current)]) {
                                throw std::logic_error("In blocking road!");
                        }
                        // try step
                        if (try_move_left()) {

                        } else if (try_move_right()) {

                        } else if (try_move_down()) {

                        } else if (try_move_up()) {

                        } else {  //!< now way now
                                if (path.empty()) {  //!< now way back too
                                        return false;  //!< dead maze !!
                                } else {  //!< back one step
                                        // anti repeat
                                        matrix_array<bool, ROW, COL>::ele[pos_2_index(current)] = false;
                                        // back one step
                                        current = path.pop();
                                        matrix_array<bool, ROW, COL>::ele[pos_2_index(current)] = true;
                                }
                        }
                }
                return true;
        }
};

#endif  //!< _MAZE_HH_
