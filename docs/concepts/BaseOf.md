# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:BaseOf
Defined in header [<xieite/concepts/BaseOf.hpp>](../../include/xieite/concepts/BaseOf.hpp)

&nbsp;

## Description
Specifies that a type is a base of another type.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Base, typename Derived>
concept BaseOf = std::is_base_of_v<Base, Derived>;
```
