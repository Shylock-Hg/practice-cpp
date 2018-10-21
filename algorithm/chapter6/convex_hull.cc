#include <iostream>
#include <type_traits>
#include <vector>
#include <initializer_list>
#include <memory>
#include <complex>
#include <array>
#include <iterator>
#include <algorithm>

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
                gen_ch_points();
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
        enum ori {IN_LINE, CLOCK, COUNTER_CLOCK};
        ori orientation(std::complex<float> zero,
                std::complex<float> a,
                std::complex<float> b) {
                float val = (a.imag() - zero.imag()) *
                        (b.real() - a.real()) -
                        (a.real() - zero.real()) *
                        (b.imag() - a.imag()); 

                if (val == 0) return IN_LINE;  // colinear 
                return (val > 0)? CLOCK : COUNTER_CLOCK; // clock or counterclock wise 
        };

        /*!
                \brief implement Graham Scan algorithm
        */
        void gen_ch_points() {
                //< find the base point -- first y min then x min
                auto base = std::min_element(_points.begin(),
                        _points.end(),
                        [](const std::complex<float> a,
                                const std::complex<float> b) -> bool {
                                if (a.real() < b.real()) {
                                        return true;
                                }
                                if (a.real() == b.real()
                                        && a.imag() < b.imag()) {
                                        return true;
                                }
                                return false;
                        });
                //< place base to first
                std::swap(base, _points.begin());
                //< sort the points by counter clock
                std::sort(_points.begin()+1, _points.end(),
                        [this](
                                std::complex<float> a,
                                std::complex<float> b) -> bool {
                                ori orien = orientation(*(this->_points.begin()),
                                        a, b);
                                if(IN_LINE == orien) {
                                        if(std::abs(a-*(this->_points.begin())) < std::abs(b-*(this->_points.begin())))
                                                return true;
                                }
                                if(COUNTER_CLOCK == orien)
                                        return true;
                                return false;
                        });
                //< 
        }
};

template<std::size_t N>
std::ostream& operator<<(std::ostream& out, const points<N>& p) {
        return p.output(out);
}

int main(int argc, char * argv[]) {
        points<5> p {{1, 1},  {2, 2}, {3, 3}, {4, 4}, {4, 5}};
        std::clog << p << std::endl;
        std::clog << "Is in one line? " << p.is_one_line() << std::endl;

        std::clog << p << std::endl;
        return 0;
}

