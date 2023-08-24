# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:DerivedFromAllOf
Defined in header [<xieite/concepts/DerivedFromAllOf.hpp>](../../include/xieite/concepts/DerivedFromAllOf.hpp)

&nbsp;

## Description
Specifies that a type is derived from several other types.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Derived, typename... Bases>
concept DerivedFromAllOf = (... && std::derived_from<Derived, Bases>);
```
