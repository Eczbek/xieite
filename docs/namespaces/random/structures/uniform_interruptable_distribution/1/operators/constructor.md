# [xieite](../../../../../../xieite.md)\:\:[random](../../../../../../random.md)\:\:[UniformInterruptableDistribution<Arithmetic_>](../../../../uniform_interruptable_distribution.md)\:\:UniformInterruptableDistribution\<\>\(\)
Defined in header [<xieite/random/uniform_interruptable_distribution.hpp>](../../../../../../../include/xieite/random/uniform_interruptable_distribution.hpp)

&nbsp;

## Description
Constructs a `xieite::random::UniformInterruptableDistribution<Arithmetic_>`. Invokes `std::unreachable()` if all possible values are excluded.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::RangeOf<xieite::math::Interval<Arithmetic_>> IntervalRange_>
UniformInterruptableDistribution(xieite::math::Interval<Arithmetic_> interval, IntervalRange_&& interruptions) noexcept;
```

&nbsp;

## [Example](../../../../uniform_interruptable_distribution.md#Example)
