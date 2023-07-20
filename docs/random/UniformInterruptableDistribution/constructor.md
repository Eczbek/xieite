# [xieite](../../xieite.md)::[random](../../random.md)::[UniformInterruptableDistribution<Number>](../UniformInterruptableDistribution.md)::UniformInterruptableDistribution
Defined in header [<xieite/random/UniformInterruptableDistribution.hpp>](../../../include/xieite/random/UniformInterruptableDistribution.hpp)

<br/>

Constructs a `xieite::random::UniformInterruptableDistribution`. Throws a `std::range_error` if all possible values are excluded

<br/><br/>

## Synopsis

<br/>

```cpp
UniformInterruptableDistribution(Number begin, Number end, const xieite::concepts::RangeOf<std::pair<Number, Number>> auto& interruptions);
```
### Parameters
- `begin` - A `Number`, one end of the range
- `end` - A `Number`, the other end of the range
- `interruptions` - A constant reference to a value of any type satisfying `xieite::concepts::RangeOf` of std::pair of two Numbers
