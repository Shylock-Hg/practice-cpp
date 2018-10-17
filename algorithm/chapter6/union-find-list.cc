#include <list>
#include <array>
#include <type_traits>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <iterator>

using equiv = std::list<int>;

template <std::size_t N>
class equiv_set {
        using _equiv = std::list<int>;

        using _equiv_set = std::array<_equiv, N>;
public:
        _equiv_set cls;
        equiv_set<N>() : cls() {
        }

        void unite(int classA, int classB) {
                if(classA >= cls.size() || classB >= cls.size()) {
                        throw std::out_of_range("Equiv out of range!");
                }
                cls[classA].sort();
                cls[classB].sort();
                cls[classA].merge(std::move(cls[classB]));
        }

        int find(int elem) const {
                int _class = 0;
                for(auto & c : cls){
                        if(c.end() != std::find(c.begin(), c.end(), elem)) {
                                return _class;
                        }
                        if(0 != c.size()) _class++;
                }
                return -1;
        }

        std::ostream& output(std::ostream& out) const {
                for (auto & c : cls) {
                        std::copy(
                                c.begin(),
                                c.end(),
                                std::ostream_iterator<int>(out, " "));
                        if(0 != c.size()) out << std::endl;
                }
                return out;
        }
};

template <std::size_t N>
std::ostream& operator<<(std::ostream& out, equiv_set<N>& a) {
        return a.output(out);
}

int main(int argc, char * argv[]) {
        equiv_set<7> a;  //!< 7 class union-find
        a.cls[0] = {1, 2, 3, 4};
        a.cls[1] = {5, 6};
        a.cls[2] = {7, 8};
        a.cls[3] = {9};
        a.cls[4] = {10, 11};
        a.cls[5] = {12, 13, 14};
        a.cls[6] = {15};

        std::cout << a << std::endl;

        a.unite(0, 1);
        std::cout << a << std::endl;

        std::cout << a.find(6) << std::endl;
        std::cout << a.find(1) << std::endl;
        std::cout << a.find(7) << std::endl;
        return 0;
}

