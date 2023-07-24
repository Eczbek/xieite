# [xieite](../../xieite.md)::[random](../../random.md)::[UniformInterruptableDistribution<Arithmetic>](../UniformInterruptableDistribution.md)::UniformInterruptableDistribution
Defined in header [<xieite/random/UniformInterruptableDistribution.hpp>](../../../include/xieite/random/UniformInterruptableDistribution.hpp)

<br/>

Constructs a `xieite::random::UniformInterruptableDistribution`. Throws a `std::range_error` if all possible values are excluded

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::RangeOf<xieite::math::Interval<Arithmetic>> IntervalRange>
UniformInterruptableDistribution(const xieite::math::Interval<Arithmetic> interval, const IntervalRange& interruptions);
```
### Template parameters
- `IntervalRange` - A type satisfying `xieite::concepts::RangeOf` of `xieite::math::Interval` of `Arithmetic`
### Parameters
- `interval` - A `xieite::math::Interval` of `Arithmetic`, the main interval
- `interruptions` - A constant `IntervalRange` reference, the interval exclusions
