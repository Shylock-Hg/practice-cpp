#include <iostream>
#include <type_traits>
#include <vector>
#include <initializer_list>
#include <memory>
#include <complex>
#include <array>
#include <iterator>

//< 67
template  <std::size_t N>
class points {
private:
        std::array<std::complex<float>, N> _points;  //< all points
        std::vector<std::complex<float>> _ch_points;  //< extreme points of convex hull
public:
        points() = default;
        explicit points(std::initializer_list<std::complex<float>> list) :
                _points {std::array<std::complex<float>, N> ()},
                _ch_points {std::vector<std::complex<float>> ()} {
                std::copy(list.begin(), list.begin()+N, _points.begin());
        };

        //< get a point inside the convex hull
        std::complex<float> inside_point() const {
                
        }

        //< check is points in one line
        bool is_one_line() const {
                if(3 > _points.size()) {
                        return true;
                }

                auto three_one_line = [](const std::complex<float> a,
                        const std::complex<float> b,
                        const std::complex<float> c) -> bool {
                        return (std::abs(c-b)+std::abs(b-a) == std::abs(c-a));
                };
                for(std::size_t i=2; i<_points.size(); i++) {
                        if(false == three_one_line(_points[0], _points[1], _points[i])) {
                                return false;
                        }
                }
                return true;
        }

        const std::vector<std::complex<float>>& get_ch_points() const {
                return _ch_points;
        }

        std::ostream& output(std::ostream& out) const {
                std::copy(_points.begin(),
                        _points.end(),
                        std::ostream_iterator<std::complex<float>> (out, " "));
                return out;
        }
private:
        void gen_ch_points() {}
};

template<std::size_t N>
std::ostream& operator<<(std::ostream& out, const points<N>& p) {
        return p.output(out);
}

int main(int argc, char * argv[]) {
        points<5> p {{1, 1},  {2, 2}, {3, 3}, {4, 4}, {4, 5}};
        std::clog << p << std::endl;
        std::clog << "Is in one line? " << p.is_one_line() << std::endl;
        return 0;
}

