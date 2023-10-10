# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SameAsAll
Defined in header [<xieite/concepts/same_as_all.hpp>](../../../include/xieite/concepts/same_as_all.hpp)

&nbsp;

## Description
Specifies that a type is the same as several other types.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
concept SameAsAll = (... || std::same_as<Source, Targets>);
```
