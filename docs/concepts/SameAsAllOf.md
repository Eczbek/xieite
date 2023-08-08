# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:SameAsAllOf
Defined in header [<xieite/concepts/SameAsAllOf.hpp>](../../include/xieite/concepts/SameAsAllOf.hpp)

&nbsp;

## Description
Specifies that a type is the same as several other types.

&nbsp;

## Synopsis
```cpp
template<typename Source, typename... Targets>
concept SameAsAllOf = (std::same_as<Source, Targets> || ...);
```
