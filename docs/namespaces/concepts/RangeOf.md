# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:RangeOf
Defined in header [<xieite/concepts/RangeOf.hpp>](../../../include/xieite/concepts/RangeOf.hpp)

&nbsp;

## Description
Specifies that a type satisfies `std::ranges::range` and contains values of a specified type.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Range, typename Value>
concept RangeOf = std::ranges::range<Range> && (std::same_as<std::ranges::range_value_t<Range>, Value> || std::convertible_to<std::ranges::range_value_t<Range>, Value>);
```