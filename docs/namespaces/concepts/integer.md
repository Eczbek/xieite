# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Integer
Defined in header [<xieite/concepts/integer.hpp>](../../../include/xieite/concepts/integer.hpp)

&nbsp;

## Description
Specifies that a type is an integral and not a boolean.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept Integer = std::integral<Type> && !std::same_as<Type, bool>;
```
