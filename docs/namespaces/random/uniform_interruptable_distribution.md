# [xieite](../../xieite.md)\:\:[random](../../random.md)\:\:UniformInterruptableDistribution\<\> \{\}
Defined in header [<xieite/random/uniform_interruptable_distribution.hpp>](../../../include/xieite/random/uniform_interruptable_distribution.hpp)

&nbsp;

## Description
A uniform random number distribution which allows excluding subintervals from the main interval.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
struct UniformInterruptableDistribution {
    template<xieite::concepts::RangeOf<xieite::math::Interval<Arithmetic_>> IntervalRange_>
    UniformInterruptableDistribution(xieite::math::Interval<Arithmetic_>, IntervalRange_&&) noexcept;

    template<std::uniform_random_bit_generator UniformRandomBitGenerator_>
    Arithmetic_ operator()(UniformRandomBitGenerator_&) noexcept;
};
```
- [UniformInterruptableDistribution\<\>\(\)](./structures/uniform_interruptable_distribution/1/operators/constructor.md)
- [operator\(\)\<\>\(\)](./structures/uniform_interruptable_distribution/1/operators/call.md)

&nbsp;

## Example
```cpp
#include <print>
#include <random>
#include "xieite/random/uniform_interruptable_distribution.hpp"

int main() {
    auto rng = std::default_random_engine(std::random_device {}());

    auto interval = xieite::math::Interval<int>(0, 5);

    std::vector<xieite::math::Interval<int>> interruptions = {
        xieite::math::Interval<int>(1, 4)
    };

    auto dist = xieite::random::UniformInterruptableDistribution<int>(interval, interruptions);

    for (int i = 0; i < 10; ++i) {
        std::println("{}", dist(rng));
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
