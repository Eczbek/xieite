# [xieite](../../xieite.md)::[random](../../random.md)::[UniformInterruptableDistribution<Number>](../UniformInterruptableDistribution.md)::operator()
Defined in header [<xieite/random/UniformInterruptableDistribution.hpp>](../../../include/xieite/random/UniformInterruptableDistribution.hpp)

<br/>

Distributes the result of a random number generator

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
Number operator()(xieite::concepts::UniformRandomBitGenerator auto& generator) const noexcept;
```
### Parameters
- `generator` - An `auto` constant reference, satisfying `xieite::concepts::UniformRandomBitGenerator`
### Return value
- A `Number`
