# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:ConvertibleToAllOf
Defined in header [<xieite/concepts/convertible_to_all_of.hpp>](../../../include/xieite/concepts/convertible_to_all_of.hpp)

&nbsp;

## Description
Specifies that a type can be converted to several other types.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
concept ConvertibleToAllOf = (... && std::convertible_to<Source, Targets>);
```
