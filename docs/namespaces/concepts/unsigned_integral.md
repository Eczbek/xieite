# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:UnsignedInteger
Defined in header [<xieite/concepts/unsigned_integer.hpp>](../../../include/xieite/concepts/unsigned_integer.hpp)

&nbsp;

## Description
Specifies that a type is an unsigned integral and not a boolean.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept UnsignedInteger = std::unsigned_integral<Type> && !std::same_as<Type, bool>;
```
