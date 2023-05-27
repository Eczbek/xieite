# [xieite](../../README.md)::[concepts](../concepts.md)::RangeOf
Defined in header [<xieite/concepts/RangeOf.hpp>](../../include/xieite/concepts/RangeOf.hpp)

<br/>

Specifies that a type satisfies `std::ranges::range` and contains values of specified type

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Range, typename Value>
concept RangeOf = std::ranges::range<Range> && std::same_as<std::ranges::range_value_t<Range>, Value>;
```
### Template parameters
- `Range` - Any type
- `Value` - Any type
