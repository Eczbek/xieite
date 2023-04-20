# `xieite::random::InterruptableUniformDistribution<Number>::operator()`
Defined in header [`<xieite/random/InterruptableUniformDistribution.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/random/InterruptableUniformDistribution.hpp)

<br/>

Distributes the result of a random number generator.

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
Number operator()(xieite::concepts::UniformRandomBitGenerator auto&& generator) noexcept;
```
### Parameters
- `generator` - An `auto` right-value reference, satisfying `xieite::concepts::UniformRandomBitGenerator`
### Return value
- A `Number`

<br/><br/>

## See also
- [`xieite::concepts::UniformRandomBitGenerator`](https://github.com/Eczbek/xieite/tree/main/docs/concepts/UniformRandomBitGenerator.md)
- [`xieite::random::InterruptableUniformDistribution`](https://github.com/Eczbek/xieite/tree/main/docs/random/InterruptableUniformDistribution.md)
