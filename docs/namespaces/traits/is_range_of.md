# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsRangeOf \{\}
Defined in header [<xieite/traits/is_range_of.hpp>](../../../include/xieite/traits/is_range_of.hpp)

&nbsp;

## [Description](../concepts/range_of.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Range, typename Value>
struct IsRangeOf
: std::bool_constant<xieite::concepts::RangeOf<Range, Value>> {};
```

&nbsp;

## [Example](../concepts/range_of.md#Example)
