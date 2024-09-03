# [xieite](../../xieite.md)\:\:[random](../../random.md)\:\:UniformInterruptableDistribution\<\> \{\}
Defined in fragment [xieite:random.UniformInterruptableDistribution](../../../src/random/uniform_interruptable_distribution.cpp)

&nbsp;

## Description
A uniform random number distribution which allows excluding subintervals from the main interval.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
struct UniformInterruptableDistribution {
    template<std::ranges::input_range IntervalRange>
    requires(std::convertible_to<std::ranges::range_value_t<IntervalRange>, xieite::math::Interval<Arithmetic>>)
    UniformInterruptableDistribution(xieite::math::Interval<Arithmetic>, IntervalRange&&) noexcept;

    template<std::uniform_random_bit_generator UniformRandomBitGenerator>
    Arithmetic operator()(UniformRandomBitGenerator&) noexcept;
};
```
- [UniformInterruptableDistribution\<\>\(\)](./structures/uniform_interruptable_distribution/1/operators/constructor.md)
- [operator\(\)\<\>\(\)](./structures/uniform_interruptable_distribution/1/operators/call.md)

&nbsp;

## Example
```cpp
import std;
import xieite;

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
