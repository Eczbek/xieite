# [xieite](../../xieite.md)\:\:[random](../../random.md)\:\:UniformDistribution
Defined in header [<xieite/random/uniform_distribution.hpp>](../../../include/xieite/random/uniform_distribution.hpp)

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
using UniformDistribution = std::conditional_t<std::integral<Number>, std::conditional_t<std::same_as<Number, bool>, std::bernoulli_distribution, std::uniform_int_distribution<Number>>, std::uniform_real_distribution<Number>>;
```
