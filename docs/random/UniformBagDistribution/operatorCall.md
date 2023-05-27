# [xieite](../../../README.md)::[random](../../random.md)::[UniformBagDistribution<Integral>](../UniformBagDistribution.md)::operator()
Defined in header [<xieite/random/UniformBagDistribution.hpp>](../../../include/xieite/random/UniformBagDistribution.hpp)

<br/>

Distributes the result of a random number generator

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
