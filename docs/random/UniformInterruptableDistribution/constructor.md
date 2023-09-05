# [xieite](../../xieite.md)\:\:[random](../../random.md)\:\:[UniformInterruptableDistribution\<Number\>](../UniformInterruptableDistribution.md)\:\:UniformInterruptableDistribution
Defined in header [<xieite/random/UniformInterruptableDistribution.hpp>](../../../include/xieite/random/UniformInterruptableDistribution.hpp)

&nbsp;

## Description
Constructs a `xieite::random::UniformInterruptableDistribution`. Throws a `std::range_error` if all possible values are excluded.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::RangeOf<xieite::math::Interval<Number>> IntervalRange>
UniformInterruptableDistribution(const xieite::math::Interval<Number> interval, const IntervalRange& interruptions);
```
