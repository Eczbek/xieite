# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:DerivedFromAll
Defined in header [<xieite/concepts/derived_from_all.hpp>](../../../include/xieite/concepts/derived_from_all.hpp)

&nbsp;

## Description
Specifies that a type is derived from several other types.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Derived, typename... Bases>
concept DerivedFromAll = (... && std::derived_from<Derived, Bases>);
```
