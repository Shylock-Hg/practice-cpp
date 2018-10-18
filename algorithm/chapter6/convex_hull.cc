#include <iostream>
#include <type_traits>
#include <array>
#include <vector>

//< 67
template  <std::size_t N>
class points {
private:
        std::array<std::array<float, 2>, N> _points;  //< all points
        std::vector<std::array<float, 2>> _ch_points;  //< extreme points of convex hull
public:
        points() = default;

        //< get a point inside the convex hull
        std::array<float, 2> inside_point() const {
                
        }

        //< check is points in one line
        bool is_one_line() const {}

        const std::vector<std::array<float, 2>>& get_ch_points() const {
                return _ch_points;
        }
private:
        void gen_ch_points() {}
};

int main(int argc, char * argv[]) {
        
        return 0;
}

