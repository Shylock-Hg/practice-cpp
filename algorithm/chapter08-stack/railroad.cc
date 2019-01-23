/*! \brief do the railroad problem by stack
 *  \author Shylock Hg
 *  \date 2018-12-31
 *  \email tcath2s@gmail.com
 * */

#include <queue>
#include <vector>
#include <type_traits>
#include <stdexcept>
#include <iostream>

#include "list_stack.hh"

std::queue<int> railroad(std::queue<int> &input);

int main(int argc, char * argv[]) {
        // std::queue<int> input {1, 0, 2, 5, 4, 3};
        std::queue<int> input;
        input.push(1);
        input.push(0);
        input.push(2);
        input.push(5);
        input.push(4);
        input.push(3);
        std::queue<int> output = railroad(input);

        while (!output.empty()) {
                std::cout << output.front() << std::endl;
                output.pop();
        }

        return 0;
}

void push_caches(std::queue<int> &input, std::vector<list_stack<int>> &caches);
void pop_cache(std::vector<list_stack<int>> &caches, std::queue<int> &output);
bool is_caches_empty(const std::vector<list_stack<int>> &caches);
void push_output(std::queue<int> &input, std::queue<int> &output);

//
std::queue<int> railroad(std::queue<int> &input) {
        // the rails to cache cars
        std::vector<list_stack<int>> caches;
        // the output 
        std::queue<int> output;

        int next = 0;

        while (!input.empty())  {
                if (next == input.front()) {
                        push_output(input, output);
                        next++;
                } else {
                        push_caches(input, caches);
                }
        }

        // while (!caches.empty()) {
        while (!is_caches_empty(caches)) {
                pop_cache(caches, output);
        }

        return output;
}

/*! \brief push the car to caches from input
*/
void push_caches(std::queue<int> &input, std::vector<list_stack<int>> &caches) {
        if (input.empty()) {
                throw std::out_of_range("Pop input out of range!");
        }

        // get the new one to resort
        int last = input.front();
        input.pop();

        for (auto & s : caches) {
                if (s.get_top() > last) {
                        s.push(last);
                        return;
                }
        }

        // new stack
        list_stack<int> s;
        s.push(last);
        caches.push_back(std::move(s));
}

/*! \brief push the car to output from input
*/
void push_output(std::queue<int> &input, std::queue<int> &output) {
        if (input.empty()) {
                throw std::out_of_range("Pop input out of range!");
        }

        int last = input.front();
        output.push(last);
        input.pop();
}

/*! \brief pop the minimum to output from caches
*/
void pop_cache(std::vector<list_stack<int>> &caches, std::queue<int> &output) {
        for (auto & s : caches) {
                if (!s.empty()) {
                        output.push(s.pop());
                        break;
                }
        }
}

bool is_caches_empty(const std::vector<list_stack<int>> &caches) {
        for (const auto & s : caches) {
                if (!s.empty()) {
                        return false;
                }
        }

        return true;
}
