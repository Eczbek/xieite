# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsRangeOf\<\> \{\}
Defined in header [<xieite/traits/is_range_of.hpp>](../../../include/xieite/traits/is_range_of.hpp)

&nbsp;

## [Description](../concepts/range_of.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Range_, typename Value_>
struct IsRangeOf
: std::bool_constant<xieite::concepts::RangeOf<Range_, Value_>> {};
```

&nbsp;

## [Example](../concepts/range_of.md#Example)
