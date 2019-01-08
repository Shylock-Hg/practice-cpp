/*! \brief 
 *  \author Shylock Hg
 *  \date 2019-01-05
 *  \email tcath2s@gmail.com
 * */

#ifndef _OFFLINE_EQUIVALENCE_SET_HH_
#define _OFFLINE_EQUIVALENCE_SET_HH_

#include <utility>
#include <limits>
#include <array>
#include <type_traits>
#include <stdexcept>
#include <vector>
#include <map>
#include <set>
#include <iostream>

#include "list_stack.hh"

template <class T>
T max_of_pair(const std::pair<T, T> &p) {
        return (p.first > p.sencond ? p.first : p.second);
}

template <std::size_t N>
class relationships {
private:
        std::array<std::pair<int, int>, N> ships;

        void find_the_members (
                std::set<int> & set,
                int c) const {
                for (const auto & p : ships) {
                        if (c == p.first) {
                                set.insert(p.second);
                        }
                        if (c == p.second) {
                                set.insert(p.first);
                        }
                }
        }

static void generate_set(std::map<int, std::set<int>> &ir,
        int key,
        std::vector<std::set<int>> &sets,
        std::set<int> &processed,
        std::size_t i) {
        const auto result = processed.find(key);
        if (result != processed.end()) {  //!< processed
                return;
        }

        sets[i].insert(key);
        processed.insert(key);
        for (const auto & s : ir[key]) {
                sets[i].insert(s);
                generate_set(ir, s, sets, processed, i);
        }
}

static void generate_sets(
        std::map<int, std::set<int>> &ir,
        std::vector<std::set<int>> & sets) {
        std::set<int> processed;
        std::size_t i = 0;
        for (const auto & p : ir) {  //!< O(M)
                const auto result = processed.find(p.first);
                if (result == processed.end()) {  //!< not processed
                        // std::clog << "New set!" << std::endl;
                        sets.push_back(std::set<int>());
                        generate_set(ir, p.first, sets, processed, i++);
                }
        }
}

public:
        relationships(std::array<std::pair<int, int>, N> && r) : ships {r} {}

        /*! \brief generate the equivalence sets from relationships
            \param relationships sets of relationships
            \retval sets of offline equivalence set
        */
        std::vector<std::set<int>> get_equivalence_set() const {
                std::vector<std::set<int>> sets;
                std::map<int, std::set<int>> ir;

                // generate intermediate representation
                // O(N^2)
                for (const auto & p : ships) {  //!< O(N)
                        auto result = ir.find(p.first);  //!< O(lgM)
                        if (result == ir.end()) {
                                std::set<int> members;
                                find_the_members(members, p.first);  //!< O(N)
                                ir.emplace(p.first, std::move(members));
                        }
                        result = ir.find(p.second);
                        if (result == ir.end()) {
                                std::set<int> members;
                                find_the_members(members, p.second);
                                ir.emplace(p.second, std::move(members));
                        }
                }
                // check the ir ok!
/*
                for (const auto & p : ir) {
                        std::clog << p.first << " ";
                        for (const auto & v : p.second) {
                                std::clog << v << " ";
                        }
                        std::clog << std::endl;
                }
                std::clog << ir.size() << std::endl;
*/

                // generate equivalence sets
                generate_sets(ir, sets);
                return sets;  //!< automatic move
        }
        
        /*! \brief get the max value in the relationships
            \retval maximum value in the relationships
        */
        int max_value() const {
                int max = std::numeric_limits<int>::min();
                for (const auto & p : ships) {
                        int temp = max_of_pair(p);
                        max = temp > max ? temp : max;
                }
                return max;
        }
};

#endif  //!< _OFFLINE_EQUIVALENCE_SET_HH_

