# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:Enumerator
Defined in header [<xieite/concepts/Enumerator.hpp>](../../include/xieite/concepts/Enumerator.hpp)

&nbsp;

## Description
Specifies that a type is an enumerator.

&nbsp;

## Synopsis
```cpp
template<typename Type>
concept Enumerator = std::is_enum_v<Type>;
```
