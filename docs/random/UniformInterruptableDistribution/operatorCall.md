# [xieite](../../xieite.md)::[random](../../random.md)::[UniformInterruptableDistribution<Arithmetic>](../UniformInterruptableDistribution.md)::operator()
Defined in header [<xieite/random/UniformInterruptableDistribution.hpp>](../../../include/xieite/random/UniformInterruptableDistribution.hpp)

<br/>

Distributes the result of a random number generator

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::UniformRandomBitGenerator UniformRandomBitGenerator>
[[nodiscard]]
Arithmetic operator()(UniformRandomBitGenerator& generator) const noexcept;
```
### Template parameters
- `UniformRandomBitGenerator` - A type satisfying `xieite::concepts::UniformRandomBitGenerator`
### Parameters
- `generator` - A constant `UniformRandomBitGenerator` reference
### Return value
- An `Arithmetic`
