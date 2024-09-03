# [xieite](../../../../../../xieite.md)\:\:[random](../../../../../../random.md)\:\:[UniformInterruptableDistribution<Arithmetic>](../../../../uniform_interruptable_distribution.md)\:\:UniformInterruptableDistribution\<\>\(\)
Defined in fragment [xieite:random.UniformInterruptableDistribution](../../../../../../../src/random/uniform_interruptable_distribution.cpp)

&nbsp;

## Description
Constructs a `xieite::random::UniformInterruptableDistribution<Arithmetic>`. Invokes `std::unreachable()` if all possible values are excluded.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::input_range IntervalRange>
requires(std::convertible_to<std::ranges::range_value_t<IntervalRange>, xieite::math::Interval<Arithmetic>>)
UniformInterruptableDistribution(xieite::math::Interval<Arithmetic> interval, IntervalRange&& interruptions) noexcept;
```

&nbsp;

## [Example](../../../../uniform_interruptable_distribution.md#Example)
