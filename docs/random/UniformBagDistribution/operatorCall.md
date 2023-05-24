# [`xieite`](../../../README.md)`::`[`random`](../../../docs/random.md)`::`[`UniformBagDistribution<Integral>`](../../../docs/random/UniformBagDistribution.md)`::operator()`
Defined in header [`<xieite/random/UniformBagDistribution.hpp>`](../../../include/random/UniformBagDistribution.hpp)

<br/>

Distributes the result of a random number generator.

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
Integral operator()(xieite::concepts::UniformRandomBitGenerator auto& generator) const noexcept;
```
### Parameters
- `generator` - An `auto` constant reference, satisfying `xieite::concepts::UniformRandomBitGenerator`
### Return value
- An `Integral`

<br/><br/>

## See also
- [`xieite::concepts::UniformRandomBitGenerator`](../../../docs/concepts/UniformRandomBitGenerator.md)
