# [`xieite`](../../../README.md)`::`[`random`](../../../docs/random.md)`::`[`UniformInterruptableDistribution<Number>`](../../../docs/random/UniformInterruptableDistribution.md)`::UniformInterruptableDistribution`
Defined in header [`<xieite/random/UniformInterruptableDistribution.hpp>`](../../../include/random/UniformInterruptableDistribution.hpp)

<br/>

Constructs a `xieite::random::UniformInterruptableDistribution`.

<br/><br/>

## Synopsis

<br/>

```cpp
UniformInterruptableDistribution(Number begin, Number end, std::span<std::pair<Number, Number>> interruptions);
```
### Parameters
- `begin` - A `Number` copy, one end of the range
- `end` - A `Number` copy, the other end of the range
- `interruptions` - A `std::span` of `std::pair`s of `Number`s
