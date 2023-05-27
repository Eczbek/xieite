# [xieite](../../../README.md)::[random](../../random.md)::[UniformInterruptableDistribution<Number>](../UniformInterruptableDistribution.md)::UniformInterruptableDistribution
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
- `begin` - A `Number` copy, one end of the range
- `end` - A `Number` copy, the other end of the range
- `interruptions` - An `auto` constant reference, satisfying `xieite::concepts::RangeOf` of std::pair of two Numbers
