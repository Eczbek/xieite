# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:BaseOfAllOf
Defined in header [<xieite/concepts/BaseOfAllOf.hpp>](../../include/xieite/concepts/BaseOfAllOf.hpp)

&nbsp;

## Description
Specifies that a type is a base of several other types.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Base, typename... Derived>
concept BaseOfAllOf = (xieite::concepts::BaseOf<Base, Derived> && ...);
```
