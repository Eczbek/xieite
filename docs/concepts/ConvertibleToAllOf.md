# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:ConvertibleToAllOf
Defined in header [<xieite/concepts/ConvertibleToAllOf.hpp>](../../include/xieite/concepts/ConvertibleToAllOf.hpp)

&nbsp;

## Description
Specifies that a type can be converted to several other types.

&nbsp;

## Synopsis
```cpp
template<typename Source, typename... Targets>
concept ConvertibleToAllOf = (std::convertible_to<Source, Targets> && ...);
```
