# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsRangeOf
Defined in header [<xieite/traits/IsRangeOf.hpp>](../../../include/xieite/traits/IsRangeOf.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Range, typename Value>
struct IsRangeOf
: std::bool_constant<xieite::concepts::RangeOf<Range, Value>> {};
```
