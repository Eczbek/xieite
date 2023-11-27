# [xieite](../../xieite.md)\:\:[random](../../random.md)\:\:UniformDistribution
Defined in header [<xieite/random/uniform_distribution.hpp>](../../../include/xieite/random/uniform_distribution.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Numeric Number>
using UniformDistribution = std::conditional_t<std::integral<Number>, std::uniform_int_distribution<Number>, std::uniform_real_distribution<Number>>;
```
