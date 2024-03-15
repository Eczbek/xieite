# [xieite](../../../../../../xieite.md)\:\:[random](../../../../../../random.md)\:\:[UniformInterruptableDistribution<Number>](../../../../uniform_interruptable_distribution.md)\:\:UniformInterruptableDistribution\(\)
Defined in header [<xieite/random/uniform_interruptable_distribution.hpp>](../../../../../../../include/xieite/random/uniform_interruptable_distribution.hpp)

&nbsp;

## Description
Constructs a `xieite::random::UniformInterruptableDistribution<Number>`. Throws a `xieite::exceptions::PossibleResultsExcludedByArguments` if all possible values are excluded.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::RangeOf<xieite::math::Interval<Number>> IntervalRange>
UniformInterruptableDistribution(xieite::math::Interval<Number> interval, IntervalRange&& interruptions);
```

&nbsp;

## [Example](../../../../uniform_interruptable_distribution.md#Example)
