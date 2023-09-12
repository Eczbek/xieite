# [xieite](../../../../xieite.md)\:\:[random](../../../../random.md)\:\:[UniformInterruptableDistribution\<Number\>](../../../UniformInterruptableDistribution.md)\:\:operator\(\)
Defined in header [<xieite/random/UniformInterruptableDistribution.hpp>](../../../../../include/xieite/random/UniformInterruptableDistribution.hpp)

&nbsp;

## Description
Distributes the result of a random number generator.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::UniformRandomBitGenerator UniformRandomBitGenerator>
Number operator()(UniformRandomBitGenerator& generator) const noexcept;
```
