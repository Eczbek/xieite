# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:DerivedFromAny
Defined in header [<xieite/concepts/derived_from_any.hpp>](../../../include/xieite/concepts/derived_from_any.hpp)

&nbsp;

## Description
Specifies that a type is derived from at least one of several other types.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Derived, typename... Bases>
concept DerivedFromAny = (... || std::derived_from<Derived, Bases>);
```
