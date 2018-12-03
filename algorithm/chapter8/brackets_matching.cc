/*! \brief 
 *  \author Shylock Hg
 *  \date 2018-12-03
 *  \email tcath2s@gmail.com
 * */

#include <array>
#include <string>
#include <algorithm>
#include <iostream>
#include <stdexcept>

#include "list_stack.hh"

bool is_matched(std::string s);

int main(int argc, char * argv[]) {
        std::cout << is_matched("(){}{}[][[[]]]") << std::endl;
        std::cout << is_matched("(({{))}}") << std::endl;
        std::cout << is_matched("Hellow World!") << std::endl;  // return true
        // std::cout << is_matched("") << std::endl; exception
        return 0;
}

bool is_matched(std::string s) {
        if (s.size() == 0) {
                throw std::invalid_argument("Err: null string!");
        }
        static const std::array<char, 3> prefix {'(', '[', '{'};
        static const std::array<char, 3> suffix {')', ']', '}'};
        list_stack<char> stk;
        for (const auto& c : s) {
                //< push prefix bracket to stack
                decltype(prefix.end()) result = std::find(
                        prefix.begin(), prefix.end(), c);
                if (result != prefix.end()) {  //!< found
                        stk.push(*result);
                }

                //< check is suffix bracket is matched
                result = std::find(
                        suffix.begin(), suffix.end(), c);
                if (result != suffix.end()) {
                        char poped = stk.pop();
                        //< check is matched
                        if (poped == '(' && *result != ')') {
                                return false;
                        } else if (poped == '[' && *result != ']') {
                                return false;
                        } else if (poped == '{' && *result != '}') {
                                return false;
                        }
                }
        }
        return true;
}
