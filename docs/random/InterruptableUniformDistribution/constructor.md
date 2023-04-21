# `xieite::random::InterruptableUniformDistribution<Number>::InterruptableUniformDistribution`
Defined in header [`<xieite/random/InterruptableUniformDistribution.hpp>`](../../../include/random/InterruptableUniformDistribution.hpp)

<br/>

Constructs a `xieite::random::InterruptableUniformDistribution`.

<br/><br/>

## Synopsis

<br/>

```cpp
InterruptableUniformDistribution(Number begin, Number end, const std::vector<std::pair<Number, Number>>& interruptions);
```
### Parameters
- `begin` - A `Number` copy, the one end of the range
- `end` - A `Number` copy, the other end of the range
- `interruptions` - A constant refernce to a `std::vector` of `std::pair`s of `Number`s

<br/><br/>

## See also
- [`xieite::random::InterruptableUniformDistribution`](../../../docs/random/InterruptableUniformDistribution.md)
