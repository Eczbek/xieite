# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:RangeOf
Defined in header [<xieite/traits/range_of.hpp>](../../../include/xieite/traits/range_of.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Range, typename Value>
struct RangeOf
: std::bool_constant<xieite::concepts::RangeOf<Range, Value>> {};
```
