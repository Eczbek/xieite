# [`xieite`](../../../README.md)`::`[`random`](../../../docs/random.md)`::`[`InterruptableUniformDistribution<Number>`](../../../docs/random/InterruptableUniformDistribution.md)`::InterruptableUniformDistribution`
Defined in header [`<xieite/random/InterruptableUniformDistribution.hpp>`](../../../include/random/InterruptableUniformDistribution.hpp)

<br/>

Constructs a `xieite::random::InterruptableUniformDistribution`.

<br/><br/>

## Synopsis

<br/>

```cpp
InterruptableUniformDistribution(Number begin, Number end, std::span<std::pair<Number, Number>> interruptions);
```
### Parameters
- `begin` - A `Number` copy, the one end of the range
- `end` - A `Number` copy, the other end of the range
- `interruptions` - A `std::span` of `std::pair`s of `Number`s
