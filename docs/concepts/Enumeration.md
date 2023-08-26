# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:Enumeration
Defined in header [<xieite/concepts/Enumeration.hpp>](../../include/xieite/concepts/Enumeration.hpp)

&nbsp;

## Description
Specifies that a type is an enumerator.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept Enumeration = std::is_enum_v<Type>;
```
