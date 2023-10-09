# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SameAsAllOf
Defined in header [<xieite/concepts/same_as_all_of.hpp>](../../../include/xieite/concepts/same_as_all_of.hpp)

&nbsp;

## Description
Specifies that a type is the same as several other types.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
concept SameAsAllOf = (... || std::same_as<Source, Targets>);
```
