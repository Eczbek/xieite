# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:ConvertibleToAll
Defined in header [<xieite/concepts/convertible_to_all.hpp>](../../../include/xieite/concepts/convertible_to_all.hpp)

&nbsp;

## Description
Specifies that a type can be converted to several other types.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
concept ConvertibleToAll = (... && std::convertible_to<Source, Targets>);
```
