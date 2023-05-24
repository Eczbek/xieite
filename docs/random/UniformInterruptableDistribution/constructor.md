# [`xieite`](../../../README.md)`::`[`random`](../../../docs/random.md)`::`[`UniformInterruptableDistribution<Number>`](../../../docs/random/UniformInterruptableDistribution.md)`::UniformInterruptableDistribution`
Defined in header [`<xieite/random/UniformInterruptableDistribution.hpp>`](../../../include/random/UniformInterruptableDistribution.hpp)

<br/>

Constructs a `xieite::random::UniformInterruptableDistribution`.

<br/><br/>

## Synopsis

<br/>

```cpp
UniformInterruptableDistribution(Number begin, Number end, const xieite::concepts::RangeOf<std::pair<Number, Number>> auto& interruptions);
```
### Parameters
- `begin` - A `Number` copy, one end of the range
- `end` - A `Number` copy, the other end of the range
- `interruptions` - An `auto` constant reference, satisfying `xieite::concepts::RangeOf` of `std::pair` of two `Number`s

<br/><br/>

## See also
- [`xieite::concepts::RangeOf`](../../../docs/concepts/RangeOf.md)
