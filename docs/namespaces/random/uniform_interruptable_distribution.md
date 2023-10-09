# [xieite](../../xieite.md)\:\:[random](../../random.md)\:\:UniformInterruptableDistribution
Defined in header [<xieite/random/uniform_interruptable_distribution.hpp>](../../../include/xieite/random/uniform_interruptable_distribution.hpp)

&nbsp;

## Description
A uniform random number distribution which allows excluding subintervals from the main interval.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Numeric Number>
struct UniformInterruptableDistribution {
    template<xieite::concepts::RangeOf<xieite::math::Interval<Number>> IntervalRange>
    UniformInterruptableDistribution(xieite::math::Interval<Number>, const IntervalRange&);

    template<xieite::concepts::UniformRandomBitGenerator UniformRandomBitGenerator>
    Number operator()(UniformRandomBitGenerator&) const;
};
```
##### Member functions
- [UniformInterruptableDistribution](./structures/uniform_interruptable_distribution/1/operators/constructor.md)
- [operator()](./structures/uniform_interruptable_distribution/1/operators/call.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <random>
#include <xieite/random/uniform_interruptable_distribution.hpp>

int main() {
    auto rng = std::default_random_engine(std::random_device {}());

    auto interval = xieite::math::Interval<int>(0, 5);

    std::vector<xieite::math::Interval<int>> interruptions {
        xieite::math::Interval<int>(1, 4)
    };

    auto dist = xieite::random::UniformInterruptableDistribution<int>(interval, interruptions);

    for (int i = 0; i < 10; ++i) {
        std::cout << dist(rng) << '\n';
    }
}
```
Possible output:
```
0
5
5
5
0
0
5
5
0
5
```
