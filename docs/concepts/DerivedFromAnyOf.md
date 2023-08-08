# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:DerivedFromAnyOf
Defined in header [<xieite/concepts/DerivedFromAnyOf.hpp>](../../include/xieite/concepts/DerivedFromAnyOf.hpp)

&nbsp;

## Description
Specifies that a type is derived from at least one of several other types.

&nbsp;

## Synopsis
```cpp
template<typename Derived, typename... Bases>
concept DerivedFromAnyOf = (std::derived_from<Derived, Bases> || ...);
```
