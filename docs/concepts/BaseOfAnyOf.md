# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:BaseOfAnyOf
Defined in header [<xieite/concepts/BaseOfAnyOf.hpp>](../../include/xieite/concepts/BaseOfAnyOf.hpp)

&nbsp;

## Description
Specifies that a type is a base of at least one of several other types.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Base, typename... Derived>
concept BaseOfAnyOf = (xieite::concepts::BaseOf<Base, Derived> || ...);
```
