# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:Integer
Defined in header [<xieite/concepts/Integer.hpp>](../../include/xieite/concepts/Integer.hpp)

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
